#pragma once
struct el_option {
    char *name;
    char *value;
};
void die(const char *msg);
int eventloop(const char *filename, struct el_option opts[], int options_size);
