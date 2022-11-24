#include <stdio.h>

extern int _add(int, int);

int main()
{
    int i = _add(5, 10);
    printf("i = %d", i);
    return 0;
}