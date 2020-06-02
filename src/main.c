#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <regex.h>
#include "eventloop.h"
#include "utils.h"

char *slice(const char *str, size_t start, size_t end)
{
    size_t len = end - start;
    char tmp[len+1];
    strncpy(tmp, &str[start], len);
    tmp[len] = 0;
    return strndup(tmp, len+1);
}

int main(int argc, char *argv[])
{
    struct el_option options[255];

    regex_t flag;
    regex_t assignment;

    if (regcomp(&flag, "^--([-a-zA-Z0-9]+)$", REG_EXTENDED)){
        die("can't compile regex");
    }

    if (regcomp(&assignment, "^--([-a-zA-Z0-9]+)=([-a-zA-Z0-9]+)$", REG_EXTENDED)){
        die("can't compile regex");
    }

    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];
        regmatch_t match[3];
        if (!regexec(&flag, arg, 2, match, 0)) {
            regmatch_t m = match[1];
            char *name = slice(arg, m.rm_so, m.rm_eo);
            options[i - 1] = (struct el_option){name, "yes"};
        } else if(!regexec(&assignment, arg, 3, match, 0)) {
            regmatch_t n = match[1];
            regmatch_t v = match[2];
            char *name = slice(arg, n.rm_so, n.rm_eo);
            char *value = slice(arg, v.rm_so, v.rm_eo);
            options[i - 1] = (struct el_option){name, value};
        } else {
            return eventloop(arg, options, i - 1);
        }
    }

    die("no file provided");

    return -1;
}
