#include <stdio.h>
#include <stdlib.h>
int main () {
    char c = getc(stdin);
    while (c != '\n') {
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        printf("%c", c);
        c = getc(stdin);
    }
    printf("\n");
   return 0;
}

