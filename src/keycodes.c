#include <SDL.h>

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
    // {SDLK_F1, MP_KEY_F + 1},
    // {SDLK_F2, MP_KEY_F + 2},
    // {SDLK_F3, MP_KEY_F + 3},
    // {SDLK_F4, MP_KEY_F + 4},
    // {SDLK_F5, MP_KEY_F + 5},
    // {SDLK_F6, MP_KEY_F + 6},
    // {SDLK_F7, MP_KEY_F + 7},
    // {SDLK_F8, MP_KEY_F + 8},
    // {SDLK_F9, MP_KEY_F + 9},
    // {SDLK_F10, MP_KEY_F + 10},
    // {SDLK_F11, MP_KEY_F + 11},
    // {SDLK_F12, MP_KEY_F + 12},
    // {SDLK_F13, MP_KEY_F + 13},
    // {SDLK_F14, MP_KEY_F + 14},
    // {SDLK_F15, MP_KEY_F + 15},
    // {SDLK_F16, MP_KEY_F + 16},
    // {SDLK_F17, MP_KEY_F + 17},
    // {SDLK_F18, MP_KEY_F + 18},
    // {SDLK_F19, MP_KEY_F + 19},
    // {SDLK_F20, MP_KEY_F + 20},
    // {SDLK_F21, MP_KEY_F + 21},
    // {SDLK_F22, MP_KEY_F + 22},
    // {SDLK_F23, MP_KEY_F + 23},
    // {SDLK_F24, MP_KEY_F + 24}
    {SDLK_0, "0"},
    {SDLK_1, "1"},
    {SDLK_2, "2"},
    {SDLK_3, "3"},
    {SDLK_4, "4"},
    {SDLK_5, "5"},
    {SDLK_6, "6"},
    {SDLK_7, "7"},
    {SDLK_8, "8"},
    {SDLK_9, "9"},
    {SDLK_a, "a"},
    {SDLK_b, "b"},
    {SDLK_c, "c"},
    {SDLK_d, "d"},
    {SDLK_e, "e"},
    {SDLK_f, "f"},
    {SDLK_g, "g"},
    {SDLK_h, "h"},
    {SDLK_i, "i"},
    {SDLK_j, "j"},
    {SDLK_k, "k"},
    {SDLK_l, "l"},
    {SDLK_m, "m"},
    {SDLK_n, "n"},
    {SDLK_o, "o"},
    {SDLK_p, "p"},
    {SDLK_q, "q"},
    {SDLK_r, "r"},
    {SDLK_s, "s"},
    {SDLK_t, "t"},
    {SDLK_u, "u"},
    {SDLK_v, "v"},
    {SDLK_w, "w"},
    {SDLK_x, "x"},
    {SDLK_y, "y"},
    {SDLK_z, "z"}
};

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

    return SDL_GetKeyName(keysym.sym);
}
