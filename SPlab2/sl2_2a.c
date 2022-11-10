#include <stdio.h>
#include <stdlib.h>

char* map(char *array, int array_length, char (*f) (char)) {
    char *res = (char *)(malloc(array_length));
    for (int i = 0; i < array_length; i++) {
        res[i] = f(array[i]);
    }
    return res;
}

int main () {
    return 0;
}