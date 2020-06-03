#include <SDL.h>
#include <ctype.h>

struct keymap_entry {
    SDL_Keycode sdl;
    char* mpv;
};

const struct keymap_entry keys[] = {
    {SDLK_RETURN, "ENTER"},
    {SDLK_ESCAPE, "ESC"},
    {SDLK_BACKSPACE, "BS"},
    {SDLK_TAB, "TAB"},
    {SDLK_PRINTSCREEN, "PRINT"},
    {SDLK_PAUSE, "PAUSE"},
    // {SDLK_SPACE, "SPACE"},
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
    {SDLK_POWER, "POWER"},
    {SDLK_MENU, "MENU"},
    {SDLK_STOP, "STOP"},
    {SDLK_MUTE, "MUTE"},
    {SDLK_VOLUMEUP, "VOLUME_UP"},
    {SDLK_VOLUMEDOWN, "VOLUME_DOWN"},
    {SDLK_AUDIONEXT, "NEXT"},
    {SDLK_AUDIOPREV, "PREV"},
    {SDLK_AUDIOSTOP, "STOP"},
    {SDLK_AUDIOPLAY, "PLAY"},
    {SDLK_AUDIOMUTE, "MUTE"},
    {SDLK_F1, "F1"},
    {SDLK_F2, "F2"},
    {SDLK_F3, "F3"},
    {SDLK_F4, "F4"},
    {SDLK_F5, "F5"},
    {SDLK_F6, "F6"},
    {SDLK_F7, "F7"},
    {SDLK_F8, "F8"},
    {SDLK_F9, "F9"},
    {SDLK_F10, "F10"},
    {SDLK_F11, "F11"},
    {SDLK_F12, "F12"},
    {SDLK_F13, "F13"},
    {SDLK_F14, "F14"},
    {SDLK_F15, "F15"},
    {SDLK_F16, "F16"},
    {SDLK_F17, "F17"},
    {SDLK_F18, "F18"},
    {SDLK_F19, "F19"},
    {SDLK_F20, "F20"},
    {SDLK_F21, "F21"},
    {SDLK_F22, "F22"},
    {SDLK_F23, "F23"},
    {SDLK_F24, "F24"}
};


const char* keycode(SDL_Keysym keysym)
{
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i) {
        if (keys[i].sdl == keysym.sym) {
            return keys[i].mpv;
        }
    }

    return NULL;
}

#define MAX_KEYNAME_SIZE 255
static char keyname[MAX_KEYNAME_SIZE];

const char* keytext(SDL_TextInputEvent e)
{
    const int mod = SDL_GetModState();

    snprintf(keyname, MAX_KEYNAME_SIZE, "%s%s%s%s%s",
        mod & KMOD_CTRL ? "Ctrl+" : "",
        mod & KMOD_ALT ? "Alt+" : "",
        mod & KMOD_GUI ? "Meta+" : "",
        mod & KMOD_SHIFT ? "Shift+" : "",
        e.text);

    return keyname;
}
