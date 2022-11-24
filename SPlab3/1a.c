#include <stdio.h>
#include <stdlib.h>

typedef struct virus { 
    unsigned short SigSize; 
    char virusName[16]; 
    unsigned char* sig; 
} virus;

virus *ptr = NULL;

void printVirus(virus* virus, FILE* output);

virus* readVirus(FILE* input);


virus* readVirus(FILE* input) {
    virus* virus;
    fread(virus->virusName, 16, sizeof(char), input);
    fread(virus->SigSize, 1, sizeof(unsigned short), input);
    return virus;
}

void printVirus(virus* virus, FILE* output) {
    char c = ' ';
    fwrite(&virus->virusName, 16, sizeof(char), output);
    fwrite(&c, 1, sizeof(char), output);
    fwrite(&virus->SigSize, 1, sizeof(unsigned short), output);
    fwrite(&c, 1, sizeof(char), output);
    c = '\n';
    fwrite(&virus->sig, 16, sizeof(unsigned char), output);
    fwrite(&c, 1, sizeof(char), output);
}

int main (int argc, char **argv) {
    FILE *fd;
    virus vir;
    fd = fopen(argv[1], "rw+");
    while (!feof(fd)) {
        readVirus(fd);
        printVirus(vir.sig, fd);
    }
    return 0;
}