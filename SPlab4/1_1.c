#include <stdio.h>

extern void _print(int, char **);

int main(int argc, char **argv)
{
    _print(argc, **argv);
    return 0;
}