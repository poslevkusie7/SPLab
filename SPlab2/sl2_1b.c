#include <stdio.h>

int main () {
    int iarray[3]; 
    float farray[3]; 
    double darray[3]; 
    char carray[3]; 

    for (int i = 0; i < 3; i++) {
        printf("&iarray[%d] = %p\n", i, &iarray[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("&farray[%d] = %p\n", i, &farray[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("&darray[%d] = %p\n", i, &darray[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("&carray[%d] = %p\n", i, &carray[i]);
    }
    return 0;
}