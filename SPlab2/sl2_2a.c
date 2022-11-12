#include <stdio.h>
#include <stdlib.h>

char* map(char *array, int array_length, char (*f) (char)) {
    char *res = (char *)(malloc(array_length));
    for (int i = 0; i < array_length; i++) {
        res[i] = f(array[i]);
    }
    return res;
}

char cens(char c) {
    if (c == '!') {
        c = '.';
    }
    return c;
}

int main () {
    char arr1[] = {'H','E','Y','!'}; 
    char* arr2 = map(arr1, 4, cens); 
    printf("%s\n", arr2); 
    free(arr2); 
    return 0;
}