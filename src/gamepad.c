#include <SDL.h>
#include "gamepad.h"
#include "utils.h"

static SDL_GameController *controller;

void add_gamepad(int id)
{
    if (SDL_IsGameController(id)) {
        controller = SDL_GameControllerOpen(id);
    }
}

void remove_gamepad(int id)
{
    SDL_Joystick* j = SDL_GameControllerGetJoystick(controller);
    SDL_JoystickID jid = SDL_JoystickInstanceID(j);

    if (controller && jid == id) {
        SDL_GameControllerClose(controller);
        controller = NULL;
    }
}

struct button_map_entry {
    int sdl;
    char* mpv;
};

struct button_map_entry_analog {
    int sdl;
    struct analog neg;
    struct analog nneg;
    struct analog npos;
    struct analog pos;
};

static const struct button_map_entry button_map[] = {
    { SDL_CONTROLLER_BUTTON_A, "GAMEPAD_ACTION_DOWN" },
    { SDL_CONTROLLER_BUTTON_B, "GAMEPAD_ACTION_RIGHT" },
    { SDL_CONTROLLER_BUTTON_X, "GAMEPAD_ACTION_LEFT" },
    { SDL_CONTROLLER_BUTTON_Y,  "GAMEPAD_ACTION_UP" },
    { SDL_CONTROLLER_BUTTON_BACK, "GAMEPAD_BACK" },
    { SDL_CONTROLLER_BUTTON_GUIDE, "GAMEPAD_MENU" },
    { SDL_CONTROLLER_BUTTON_START, "GAMEPAD_START" },
    { SDL_CONTROLLER_BUTTON_LEFTSTICK, "GAMEPAD_LEFT_STICK" },
    { SDL_CONTROLLER_BUTTON_RIGHTSTICK, "GAMEPAD_RIGHT_STICK" },
    { SDL_CONTROLLER_BUTTON_LEFTSHOULDER, "GAMEPAD_LEFT_SHOULDER" },
    { SDL_CONTROLLER_BUTTON_RIGHTSHOULDER, "GAMEPAD_RIGHT_SHOULDER" },
    { SDL_CONTROLLER_BUTTON_DPAD_UP, "GAMEPAD_DPAD_UP" },
    { SDL_CONTROLLER_BUTTON_DPAD_DOWN, "GAMEPAD_DPAD_DOWN" },
    { SDL_CONTROLLER_BUTTON_DPAD_LEFT, "GAMEPAD_DPAD_LEFT" },
    { SDL_CONTROLLER_BUTTON_DPAD_RIGHT, "GAMEPAD_DPAD_RIGHT" }
};

static const struct button_map_entry_analog analog_map[] = {
    // 0 -> sdl enum
    // 1 -> negative state
    // 2 -> neutral-negative state
    // 3 -> neutral-positive state
    // 4 -> positive state
    { SDL_CONTROLLER_AXIS_LEFTX,
        {"GAMEPAD_LEFT_STICK_LEFT", "keydown"},
        {"GAMEPAD_LEFT_STICK_LEFT", "keyup"},
        {"GAMEPAD_LEFT_STICK_RIGHT", "keyup"},
        {"GAMEPAD_LEFT_STICK_RIGHT", "keydown"} },

    { SDL_CONTROLLER_AXIS_LEFTY,
        {"GAMEPAD_LEFT_STICK_UP", "keydown"},
        {"GAMEPAD_LEFT_STICK_UP", "keyup"},
        {"GAMEPAD_LEFT_STICK_DOWN", "keyup"},
        {"GAMEPAD_LEFT_STICK_DOWN", "keydown"} },

    { SDL_CONTROLLER_AXIS_RIGHTX,
        {"GAMEPAD_RIGHT_STICK_LEFT", "keydown"},
        {"GAMEPAD_RIGHT_STICK_LEFT", "keyup"},
        {"GAMEPAD_RIGHT_STICK_RIGHT", "keyup"},
        {"GAMEPAD_RIGHT_STICK_RIGHT", "keydown"} },

    { SDL_CONTROLLER_AXIS_RIGHTY,
        {"GAMEPAD_RIGHT_STICK_UP", "keydown"},
        {"GAMEPAD_RIGHT_STICK_UP", "keyup"},
        {"GAMEPAD_RIGHT_STICK_DOWN", "keyup"},
        {"GAMEPAD_RIGHT_STICK_DOWN", "keydown"} },

    { SDL_CONTROLLER_AXIS_TRIGGERLEFT,
        {NULL,NULL},
        {NULL,NULL},
        {"GAMEPAD_LEFT_TRIGGER", "keyup"},
        {"GAMEPAD_LEFT_TRIGGER", "keydown"} },

    { SDL_CONTROLLER_AXIS_TRIGGERRIGHT,
        {NULL,NULL},
        {NULL,NULL},
        {"GAMEPAD_RIGHT_TRIGGER", "keyup"},
        {"GAMEPAD_RIGHT_TRIGGER", "keyup"} },
};

char* gamepad_lookup_key(int sdl_key)
{
    for (int i = 0; i < MP_ARRAY_SIZE(button_map); i++) {
        if (button_map[i].sdl == sdl_key) {
            return button_map[i].mpv;
        }
    }
    return NULL;
}

struct analog gamepad_lookup_analog_key(int sdl_key, int16_t value)
{
    const int sdl_axis_max = 32767;
    const float activation_threshold = sdl_axis_max * 0.33;
    const float noise_threshold = sdl_axis_max * 0.06;

    // sometimes SDL just keeps shitting out low values around 0 that mess
    // with key repeating code
    if (value < noise_threshold && value > -noise_threshold) {
        return (struct analog){NULL,NULL};
    }

    for (int i = 0; i < MP_ARRAY_SIZE(analog_map); i++) {
        if (analog_map[i].sdl == sdl_key) {
            if (value >= sdl_axis_max - activation_threshold) {
                return analog_map[i].pos;
            }

            if (value <= activation_threshold - sdl_axis_max) {
                return analog_map[i].neg;
            }
            return value > 0 ? analog_map[i].npos : analog_map[i].nneg;
        }
    }

    return (struct analog){NULL,NULL};
}
