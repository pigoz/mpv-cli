#include <SDL.h>
#include <ctype.h>

struct keymap_entry {
    SDL_Keycode sdl;
    char* mpv;
};

const SDL_Keycode blacklist[] = {
    SDLK_LSHIFT,
    SDLK_RSHIFT,
    SDLK_LALT,
    SDLK_RALT,
    SDLK_LCTRL,
    SDLK_RCTRL,
    SDLK_LGUI,
    SDLK_RGUI,
};

const struct keymap_entry keys[] = {
    {SDLK_RETURN, "ENTER"},
    {SDLK_ESCAPE, "ESC"},
    {SDLK_BACKSPACE, "BS"},
    {SDLK_TAB, "TAB"},
    {SDLK_PRINTSCREEN, "PRINT"},
    {SDLK_PAUSE, "PAUSE"},
    {SDLK_SPACE, "SPACE"},
    {SDLK_INSERT, "INS"},
    {SDLK_HOME, "HOME"},
    {SDLK_PAGEUP, "PGUP"},
    {SDLK_DELETE, "DEL"},
    {SDLK_END, "END"},
    {SDLK_PAGEDOWN, "PGDWN"},
    {SDLK_RIGHT, "RIGHT"},
    {SDLK_LEFT, "LEFT"},
    {SDLK_DOWN, "DOWN"},
    {SDLK_UP, "UP"},
    {SDLK_KP_ENTER, "KP_ENTER"},
    {SDLK_KP_1, "KP1"},
    {SDLK_KP_2, "KP2"},
    {SDLK_KP_3, "KP3"},
    {SDLK_KP_4, "KP4"},
    {SDLK_KP_5, "KP5"},
    {SDLK_KP_6, "KP6"},
    {SDLK_KP_7, "KP7"},
    {SDLK_KP_8, "KP8"},
    {SDLK_KP_9, "KP9"},
    {SDLK_KP_0, "KP0"},
    // {SDLK_KP_PERIOD, MP_KEY_KPDEC},
    // {SDLK_POWER, MP_KEY_POWER},
    // {SDLK_MENU, MP_KEY_MENU},
    // {SDLK_STOP, MP_KEY_STOP},
    // {SDLK_MUTE, MP_KEY_MUTE},
    // {SDLK_VOLUMEUP, MP_KEY_VOLUME_UP},
    // {SDLK_VOLUMEDOWN, MP_KEY_VOLUME_DOWN},
    // {SDLK_KP_COMMA, MP_KEY_KPDEC},
    // {SDLK_AUDIONEXT, MP_KEY_NEXT},
    // {SDLK_AUDIOPREV, MP_KEY_PREV},
    // {SDLK_AUDIOSTOP, MP_KEY_STOP},
    // {SDLK_AUDIOPLAY, MP_KEY_PLAY},
    // {SDLK_AUDIOMUTE, MP_KEY_MUTE},
};


#define MAX_KEYNAME_SIZE 255
static char keyname[MAX_KEYNAME_SIZE];
static char keyname_mod[MAX_KEYNAME_SIZE];

const char* keycode(SDL_Keysym keysym)
{
    for (int i = 0; i < sizeof(blacklist) / sizeof(blacklist[0]); ++i) {
        if (blacklist[i] == keysym.sym) {
            return NULL;
        }
    }

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i) {
        if (keys[i].sdl == keysym.sym) {
            return keys[i].mpv;
        }
    }

    snprintf(keyname, MAX_KEYNAME_SIZE, "%s", SDL_GetKeyName(keysym.sym));

    if (keysym.sym >= SDLK_a && keysym.sym <= SDLK_z) {
        keyname[0] = tolower(keyname[0]);
    }

    const int mod = SDL_GetModState();

    snprintf(keyname_mod, MAX_KEYNAME_SIZE, "%s%s%s%s%s",
        mod & KMOD_CTRL ? "Ctrl+" : "",
        mod & KMOD_ALT ? "Alt+" : "",
        mod & KMOD_GUI ? "Meta+" : "",
        mod & KMOD_SHIFT ? "Shift+" : "",
        keyname);

    return keyname_mod;
}
