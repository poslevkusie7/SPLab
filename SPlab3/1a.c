#include <stdio.h>
#include <stdlib.h>

typedef struct virus { 
    unsigned short SigSize; 
    char virusName[16]; 
    unsigned char* sig; 
} virus;

void printVirus(virus* virus, FILE* output);

void printVirus(virus* virus, FILE* output) {
    fwrite(&virus->virusName, 16, sizeof(char), output);
    fwrite(' ', 1, sizeof(char), output);
    fwrite(&virus->SigSize, 1, sizeof(unsigned short), output);
    fwrite(' ', 1, sizeof(char), output);
    fwrite(&virus, 16, sizeof(unsigned char), output);
    fwrite('\n', 1, sizeof(char), output);
}

int main () {
    return 0;
}