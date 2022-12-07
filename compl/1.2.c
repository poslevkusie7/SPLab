#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main (int argc, char **argv) {
    int c = getchar();
    int adrr;
    if ((strcmp(argv[1], "-D") == 0)) {
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

    else if ((argv[1][0] == '-') && (argv[1][1] == 'i')) {
        FILE *input;
        char c;
        char *buff;
        buff = (char*)malloc(sizeof(char));
        input = fopen("input1", "rb");
        fread(&c, sizeof(char), 1, input);
        unsigned counter = 1;
        while (c != '\n'){
            fread(&c, sizeof(char), 1, input);
            counter++;
            buff = (char*)realloc(buff, sizeof(char) * (counter));
            buff[counter ] = c;
        }

        if ((argv[2][0] == '+') && (argv[2][1] == 'e')) { 
        char elem = buff[0];       
        int j = 2;
        int ind = 0;
        while (elem != -1) {
            printf("while\n");
            if (elem == '\n') {  
                printf("\n");
                j = 2; 
                elem = buff[ind];     
                continue;
                ind++;
            }
            elem = elem + (argv[2][j] - '0');
            printf("%c", c);
            elem = buff[ind];    
            ind++;
            if (elem == EOF) {break;}
            j++;
        }
        return 0;
        }
        else if ((argv[2][0] == '-') && (argv[2][1] == 'e')) {
            char elem = buff[0];       
            int j = 2;
            int ind = 0;
            while (elem != -1) {
                if (elem == '\n') {   
                    printf("\n");
                    j = 2;
                    elem = buff[ind]; 
                    ind++;    
                    continue;
                }
                elem = elem - (argv[1][j] - '0');
                printf("%c", c);
                elem = buff[ind];    
                ind++;
                j++;
            }
            return 0;
        }
    }

    else if (argc == 1){
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


