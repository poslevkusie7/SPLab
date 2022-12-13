#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s",i, argv[i]);
    }
    int adrr;
    if ((strcmp(argv[1], "-D") == 0)) {
        int c = getchar();      
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
    else if ((argv[1][0] == '+') && (argv[1][1] == 'e')) {  
        int c = getchar();      
        int j = 2;
        while (c != -1) {
            printf("while\n");
            if (c == '\n') {  
                printf("\n");
                j = 2; 
                c = getc(stdin);     
                continue;
            }
            c = c + (argv[1][j] - '0');
            printf("%c", c);
            c = getchar();    
            if (c == EOF) {break;}
            j++;
        }
        return 0;
    }
    else if ((argv[1][0] == '-') && (argv[1][1] == 'e')) {
        int c = getchar();
        int j = 2;
        while (c != -1) {
            if (c == '\n') {   
                printf("\n");
                j = 2;
                c = getc(stdin);     
                continue;
            }
            c = c - (argv[1][j] - '0');
            printf("%c", c);
            c = getc(stdin);    
            j++;
        }
        return 0;
    }
/*
    else if ((argv[1][0] == '-') && (argv[1][1] == 'i')) {
        FILE *input;
        char c;
        input = fopen("input.txt", "r+");
        printf("ERROR0\n");
        fread(&c, sizeof(char), 1, input);
        printf("ERROR\n");
        if ((argv[2][0] == '+') && (argv[2][1] == 'e')) {
            printf("ERROR1\n");
            int c = getchar();      
            int j = 2;
            while (c != -1) {
                printf("while\n");
                if (c == '\n') {  
                    printf("\n");
                    j = 2; 
                    fread(&c, sizeof(char), 1, input);;     
                    continue;
                }
                c = c + (argv[1][j] - '0');
                printf("%c", c);
                c = getchar();    
                if (c == EOF) {break;}
                j++;
            }
        }
    printf("ERROR2\n");
    }
*/

    else if (argc == 1){
        int c = getchar();
         while (c != '\n') {
            if ('a' <= c && c <= 'z') {
                c += 'A' - 'a';
            }
            printf("%c", c); //норм строка в капсе
            c = getc(stdin);    
        }
        printf("\n");
        return 0;
    }
    else 
    return 0;
}


