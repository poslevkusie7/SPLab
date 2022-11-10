#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFSIZE 10

char* map(char *array, int array_length, char (*f) (char));

char my_get(char c); 
/* Ignores c, reads and returns a character from stdin using fgetc. */ 

char cprt(char c); 
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. 
Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */ 

char encrypt(char c); 
/* Gets a char c and returns its encrypted form by adding 3 to its value. If c is not between 0x20 and 0x7E it is returned unchanged */ 

char decrypt(char c); 
/* Gets a char c and returns its decrypted form by reducing 3 to its value. If c is not between 0x20 and 0x7E it is returned unchanged */ 

char xprt(char c); 
/* xprt prints the value of c in a hexadecimal representation followed by a new line, and returns c unchanged. */ 


char* map(char *array, int array_length, char (*f) (char)) {
    char *res = (char *)(malloc(array_length));
    for (int i = 0; i < array_length; i++) {
        res[i] = f(array[i]);
    }
    return res;
}


char my_get(char c) {
    c = fgetc(stdin);
    return c;
}

char cprt(char c) {
    if (' ' < c && c < '~') {printf("%d\n", c);}
    else {printf(".");}
    return c;
}

char encrypt(char c) {
    if (' ' < c && c < '~') {return c + 3;}
    else {return c;}
}

char decrypt(char c) {
    if (' ' < c && c < '~') {return c - 3;}
    else {return c;}
}

char xprt(char c) {
    printf("%x\n", c);
    return c;
}

int main () {
    char arr1[BUFFSIZE]; 
    char* arr2 = map(arr1, BUFFSIZE, my_get); 
    char* arr3 = map(arr2, BUFFSIZE, cprt); 
    char* arr4 = map(arr3, BUFFSIZE, xprt); 
    char* arr5 = map(arr4, BUFFSIZE, encrypt); 
    char* arr6 = map(arr5, BUFFSIZE, decrypt); 
    /*
    printf("%c\n", my_get('f'));
    cprt('f');
    printf("%c\n", encrypt('f'));
    printf("%c\n", decrypt('f'));
    printf("%c\n", xprt('f'));
    */
    free(arr2); 
    free(arr3); 
    free(arr4); 
    free(arr5); 
    free(arr6); 
    return 0;
}