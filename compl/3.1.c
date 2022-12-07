#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct virus { 
    unsigned short SigSize; 
    char virusName[16]; 
    unsigned char* sig; 
} virus;

struct Node
{
    virus *elem;
    struct Node *next;
};


void printVirus(virus* virus, FILE* output);

virus* readVirus(FILE* input);


virus* readVirus(FILE* input) {
    struct virus *tmp;
    tmp = (struct virus *)malloc(sizeof(struct virus));
    unsigned char buf;
    int fd = fread(&buf, 1, 1, input);
    if (fd == 0) {
        return NULL;
    }
    fread(&tmp->SigSize, 1, 1, input);
    tmp->SigSize = (tmp->SigSize << 8) | buf;
    printf("size: %x\n", tmp->SigSize);
    fread(&tmp->virusName, sizeof(char) * 16, 1, input);
    tmp->sig = (unsigned char *)malloc(sizeof(unsigned char) * (tmp->SigSize + 1));
    fread(tmp->sig, tmp->SigSize, 1, input);
    //printf("STRLEN: %d\n", strlen(tmp->sig));
    //(tmp->sig)[tmp->SigSize] = 0;
    //printf("SIG: %x\n",(tmp->sig)[0]);
    return tmp;
}

void printVirus(virus *virus, FILE* output) {
    fwrite(&virus->SigSize, sizeof(unsigned short), 1, output);
    printf("N: %d\n", virus->SigSize);
    fwrite(&virus->virusName, sizeof(char) * 16, 1, output);
    printf("NAME: %s\n", virus->virusName);
    fwrite(virus->sig, virus->SigSize, 1, output);
    printf("SIG: ");
    for (int i = 0; i < virus->SigSize; i++) {
        printf("%x ", virus->sig[i]);
    }
    printf("\n");
}

void fre(struct Node * begin) {
    struct Node *tmp = begin, *tmp1;
    while (tmp != NULL) {
        tmp1 = tmp;
        tmp = tmp->next;
        free(tmp1);
    }
}

int main (int argc, char **argv) {
    struct Node *tmp, *begin = NULL;
    FILE *input;
    input = fopen("input", "r");
    FILE *output;
    output = fopen("output", "w");
    while (!feof(input)) {
        tmp = (struct Node *)malloc(sizeof(struct Node));
        //tmp->elem = (struct virus *)malloc(sizeof(struct virus));
        tmp->elem = readVirus(input);
        if (tmp->elem == NULL) {
            break;
        }
        tmp->next = begin;
        begin = tmp;
    }
    tmp = begin;
    while (tmp != NULL)
    {
        printVirus(tmp->elem, output);
        tmp = tmp->next;
    }
    fclose(input);
    fclose(output);
    fre(begin);
    return 0;
}