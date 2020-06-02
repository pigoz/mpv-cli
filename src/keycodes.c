#include <mpv/client.h>
#include <SDL.h>

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
    {SDLK_SPACE, "SPACE"},
    // {SDLK_INSERT, MP_KEY_INSERT},
    // {SDLK_HOME, MP_KEY_HOME},
    // {SDLK_PAGEUP, MP_KEY_PAGE_UP},
    // {SDLK_DELETE, MP_KEY_DELETE},
    // {SDLK_END, MP_KEY_END},
    // {SDLK_PAGEDOWN, MP_KEY_PAGE_DOWN},
    // {SDLK_RIGHT, MP_KEY_RIGHT},
    // {SDLK_LEFT, MP_KEY_LEFT},
    // {SDLK_DOWN, MP_KEY_DOWN},
    // {SDLK_UP, MP_KEY_UP},
    // {SDLK_KP_ENTER, MP_KEY_KPENTER},
    // {SDLK_KP_1, MP_KEY_KP1},
    // {SDLK_KP_2, MP_KEY_KP2},
    // {SDLK_KP_3, MP_KEY_KP3},
    // {SDLK_KP_4, MP_KEY_KP4},
    // {SDLK_KP_5, MP_KEY_KP5},
    // {SDLK_KP_6, MP_KEY_KP6},
    // {SDLK_KP_7, MP_KEY_KP7},
    // {SDLK_KP_8, MP_KEY_KP8},
    // {SDLK_KP_9, MP_KEY_KP9},
    // {SDLK_KP_0, MP_KEY_KP0},
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

char* keycode(SDL_Keysym keysym)
{
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); ++i) {
        if (keys[i].sdl == keysym.sym) {
            return keys[i].mpv;
        }
    }
    // TODO so we can tell something went wrong
    return "NOT~FOUND";
}
