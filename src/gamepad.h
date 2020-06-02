#pragma once
#include <stdint.h>

struct analog {
    char *key;
    char *state;
};

void add_gamepad(int id);
void remove_gamepad(int id);
char* gamepad_lookup_key(int sdl_key);
struct analog gamepad_lookup_analog_key(int sdl_key, int16_t value);
