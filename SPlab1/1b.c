#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {
    char c = getc(stdin);
    int adrr;
    int j = 1;
    if (argc == 2 && (strcmp(argv[j], "-D") == 0)) {
        while (c != '\n') {
            adrr = (int) c;
            fprintf(stderr, "%x ", adrr); // дебаг в стдерр
            if ('a' <= c && c <= 'z') {
                c += 'A' - 'a';
            }
            adrr = (int) c;
            fprintf(stderr, "%x\n", adrr); // дебаг в стдерр
            printf("%c", c); //норм строка в капсе
            c = getc(stdin);    
        }
        printf("\n");

    }
    else if (argc > 1) {return 1;}
    else {
         while (c != '\n') {
            if ('a' <= c && c <= 'z') {
                c += 'A' - 'a';
            }
            printf("%c", c); //норм строка в капсе
            c = getc(stdin);    
        }
        printf("\n");
    }
    return 0;
}





