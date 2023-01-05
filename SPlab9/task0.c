#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct {
    char debug_mode;
    char file_name[128];
    int unit_size;
    unsigned char mem_buf[10000];
    size_t mem_count;
    char notation;
    /*
    .
    .
    Any additional fields you deem necessary
    */
} state;

void toggleDebugMode (state* s);

void setFileName (state* s);

void examineElfFile (state* s);

void printSectionNames (state* s);

void printSymbols (state* s);

void relocationTables (state* s);

void quit (state* s);


void toggleDebugMode (state* s) {
   if (s->debug_mode) {
    s->debug_mode = 0;
    printf("%s\n","Debug flag now off");
   }
   else {
    s->debug_mode = 1;
    printf("%s\n","Debug flag now on");
   }
}

void setFileName (state* s) {
    fscanf(stdin, "%s", s->file_name); 
    if (s->debug_mode) {
        printf("Debug: file name set to %s\n", s->file_name);
    }
}

void examineElfFile (state* s) {
    printf("Set file name:\n");
    setFileName(s);

}

void printSectionNames (state* s) {
    printf("not emplement yet\n");
}

void printSymbols (state* s) {
    printf("not emplement yet\n");
}

void relocationTables (state* s) {
    printf("not emplement yet\n");
}

void quit (state* s) {
    //Quit should unmap and close any mapped or open files, and "exit normally". 
    if(s->debug_mode) {
        printf("quitting...\n");
    }
    exit(0);
}


struct fun_desc {
	char *name;
	void (*fun) ();
};

struct fun_desc menu[] = {
    {"Toggle Debug Mode", toggleDebugMode},
    {"Examine ELF File", examineElfFile},
    {"Print Section Names", printSectionNames},
    {"Print Symbols", printSymbols},
    {"Relocation Tables", relocationTables},
    {"Quit",quit},
    {NULL,NULL}
};

int main (int argc, char **argv) {
    int option;
    int  i;
    state* st = (state *)malloc(sizeof(state));

    while (1) {
        if (st->debug_mode) {
            printf("unit_size = %d\n", st->unit_size);
            printf("file_name = %s\n", st->file_name);
            printf("mem_count = %zu\n", st->mem_count);
        }
        i = 0;
        printf("\n");
        printf("Choose action:\n");
        while (menu[i].name != NULL) {
            printf("%d - %s\n", i, menu[i].name);
            i++;
        }
        printf("\n");
        printf("Option : ");
        scanf("%d", &option);
        printf("\n");
        if (option >= 0 && option < 9) {
            menu[option].fun(st);
        }
    }
    free(st);
    return 0;
}