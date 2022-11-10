#include <stdio.h>

int main () {
    int iarray[] = {1,2,3}; 
    char carray[] = {'a','b','c'}; 
    int* iarrayPtr = iarray; 
    char* carrayPtr = carray; 
    for (int i = 0; i < 3; i++) {
        printf("iarray[%d] = %d\n", i, *(iarrayPtr + i));
    }
    for (int i = 0; i < 3; i++) {
        printf("carray[%d] = %c\n", i, *(carrayPtr + i));
    }
    return 0;
}