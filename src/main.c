#include "eventloop.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        die("pass a single media file as argument");

    return eventloop(argv[1]);
}
