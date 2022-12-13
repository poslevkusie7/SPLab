#include <stdio.h>

int main () {
    FILE * output;
    output = fopen("input1", "w");
    //05 00 56 49 52 55 53 00 00 00 00 00 00 00 00 00 00 00 31 32 33 34 35
    unsigned char c = 'A';
    fwrite(&c, sizeof(unsigned char), 1, output);
    c = 'B';
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 'C';
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 'D';
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 'E';
    
    return 0;
}