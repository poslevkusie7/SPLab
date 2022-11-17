#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void printHex (char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%x", buffer[i]);
    }
    printf("\n");
}

int main () {
    FILE *iofile;
    int num;
    char *buff;
    buff = (char*)malloc(sizeof(char));
 
    iofile = fopen("example.txt", "rb");
    fread(&num, sizeof(char), 1, iofile);
    unsigned counter = 1;
    buff[counter - 1] = num;
    while (num != '\n'){
        fread(&num, sizeof(char), 1, iofile);
        counter++;
        buff = (char*)realloc(buff, sizeof(char) * (counter));
        buff[counter - 1] = num;
    }
    printHex(buff, counter - 1);
    fclose(iofile);
    free(buff);
    return 0;
}