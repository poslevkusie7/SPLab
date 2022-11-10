#include <stdio.h>
#include <stdlib.h>
char quit(char c) {
    if (c == 'q') {exit(0);}
    else {return c;}
}

int main () {
    char c;
    scanf("%c", &c);
    printf("%c\n", quit(c));
    return 0;
}