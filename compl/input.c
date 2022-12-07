#include <stdio.h>

int main () {
    FILE * output;
    output = fopen("input", "w");
    //05 00 56 49 52 55 53 00 00 00 00 00 00 00 00 00 00 00 31 32 33 34 35
    unsigned char c = 0x05;
    fwrite(&c, sizeof(unsigned char), 1, output);
    c = 0x00;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x56;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x49;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x52;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x55;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x53;
    fwrite(&c, sizeof(unsigned char), 1, output);
    for (int i = 0; i < 11; i++) {
        c = 0x00;
        fwrite(&c, sizeof(unsigned char), 1, output);
    }
     c = 0x31;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x32;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x33;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x34;
    fwrite(&c, sizeof(unsigned char), 1, output);
     c = 0x35;
    fwrite(&c, sizeof(unsigned char), 1, output);
    fclose(output);
    return 0;
}