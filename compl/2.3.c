#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fun_desc {
    char *name;
    char (*fun)(char);
} menu;

void quit(int c);

char* map(char *array, int array_length, char (*f) (char));

char my_get(char c); 
/* Ignores c, reads and returns a character from stdin using fgetc. */ 

char censor(char c);

char cprt(char c); 
/* If c is a number between 0x20 and 0x7E, cprt prints the character of 
ASCII value c followed by a new line. 
Otherwise, cprt prints the dot ('.') character. After printing, cprt returns 
the value of c unchanged. */ 

char encrypt(char c); 
/* Gets a char c and returns its encrypted form by adding 3 to its value. 
If c is not between 0x20 and 0x7E it is returned unchanged */ 

char decrypt(char c); 
/* Gets a char c and returns its decrypted form by reducing 3 to its value. 
If c is not between 0x20 and 0x7E it is returned unchanged */ 

char xprt(char c); 
/* xprt prints the value of c in a hexadecimal representation followed 
by a new line, and returns c unchanged. */ 


void menu_print(void);

char str[256];
int cnt;

void quit(int c) {
    if (c == 6) {exit(0);}
    else if (c == 0) {
        cnt = 0;
        scanf("%s", str);
        printf("DONE.\n");
    }
}

char* map(char *array, int array_length, char (*f) (char)) {
    char *res = (char *)(malloc(array_length));
    for (int i = 0; i < array_length; i++) {
        res[i] = f(array[i]);
    }
    return res;
}


char my_get(char c) {
    char x = str[cnt];
    cnt++;
    return x;
}

char cprt(char c) {
    if ((c >= '!') && (c < '~')) {printf("%c\n", c);}
    else {printf(".\n");}
    return c;
}

char censor(char c) {
    return c;
}

char encrypt(char c) {
    if ((c >= '!') && (c < '~')) {return (c + 3);}
    else {return c;}
}

char decrypt(char c) {
    if ((c >= '!') && (c < '~')) {return (c - 3);}
    else {return c;}
}

char xprt(char c) {
    if ((c >= '!') && (c < '~')) {printf("%x\n", c);}
    else {printf(".\n");}
    return c;
}


void menu_print(void) {
    printf("Please choose a function: \n");
    printf("    0)  Get string\n");
    printf("    1)  Print string\n");
    printf("    2)  Print hex\n");
    printf("    3)  Censor\n");
    printf("    4)  Encrypt\n");
    printf("    5)  Decrypt\n");
    printf("    6)  Quit\n");
}

int main (int argc, char **argv) {
    int c;
    char a = 'a';
    menu arr[5];
    arr[0].name = (char *)malloc(5 * sizeof(char));
    strcpy(arr[0].name, "cprt");
    arr[0].fun = cprt;
    arr[3].name = (char *)malloc(8 * sizeof(char));
    strcpy(arr[3].name, "encrypt");
    arr[3].fun = encrypt;
    arr[2].name = (char *)malloc(7 * sizeof(char));
    strcpy(arr[2].name, "censor");
    arr[2].fun = censor;
    arr[4].name = (char *)malloc(8 * sizeof(char));
    strcpy(arr[4].name, "decrypt");
    arr[4].fun = decrypt;
    arr[1].name = (char *)malloc(5 * sizeof(char));
    strcpy(arr[1].name, "xprt");
    arr[1].fun = xprt;
    while (1) {
        menu_print();
        printf("Option : ");
        scanf("%d", &c);
        printf("\n");
        printf("Within bounds\n");
        quit(c);
        if (c == 0 || c == 6) { continue; }
        for (int i = 0; i < strlen(str); i++) {
            if (c == 4 || c == 5) {
                str[i] = arr[c - 1].fun(my_get(a));
            }
            else {
                arr[c - 1].fun(my_get(a));
            }
        }
        cnt = 0;
        printf("DONE.\n");
    }
   
    return 0;
}