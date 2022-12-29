#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*how can I check if addr value lenght location is correct or not?
 do I need to add smth debug checks its dont written in task correctly
 
 Also its impossible to read or execute this files with out a programm. (permission denied)
 */

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

void setUnitSize (state* s);

void loadIntoMemory (state* s);

void toggleDisplayMode (state* s);

void memoryDisplay (state* s);

void saveIntoFile (state* s);

void memoryModify (state* s);

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

void setUnitSize (state* s){
    int size;
    char valid = 0;
    scanf("%d", &size);
    if ((size == 1) || (size == 2) || (size == 4)) {
        valid = 1;
        s->unit_size = size;
    }
    if (s->debug_mode) {
        if (valid)
            printf("Debug: set unit size to %d\n", s->unit_size);
        else 
            printf("Debug: error: unit size %d not valid\n", size);
    }
}
//и тут тоже дабаг нужен в теории (хотя по условию я все сделал вроде)
void loadIntoMemory (state* s) {
    int location, length;
    if (!strcmp(s->file_name, "")) {
        printf("Error: file name is empty\n");
    }
    else {
        FILE *fd;
        if (!(fd = fopen(s->file_name, "r"))) {
            printf("Error: file isnt opening\n");
        }
        else {
            printf("Please enter <location> <length>\n");
            scanf("%x %d", &location, &length);
            if (s->debug_mode) {
                printf("Debug: file name is %s\n", s->file_name);
            }
            fseek(fd, location, SEEK_SET);
            int ret = fread(s->mem_buf, s->unit_size, length, fd);
            if (ret < 0) 
                printf("Error: error while reading from file %s\n", s->file_name);
            else {
                s->mem_count = ret * s->unit_size;
                printf("Loaded %d units into memory\n", length);
            }
        }
        fclose(fd);
    }
}

void toggleDisplayMode (state* s) {
    if (s->notation == 0) {
        s->notation = 1;
        printf("Display flag now on, hexadecimal representation\n");
    }
    else {
        s->notation = 0;
        printf("Display flag now off, decimal representation\n");
    }
}
// надо понять в какой момент делать \n
void memoryDisplay (state* s) {
    int address, length;
    printf("Please enter <address> <length>\n");
    scanf("%x %d", &address, &length);
    if (s->notation) {
        printf("Hexadecimal\n");
        printf("===========\n");
        for (int i = address; i < length * s->unit_size; i++) {
            printf("%x", s->mem_buf[i]);
            if (i % s->unit_size == 0) {
                printf("\n");
            }
        }
    }
    else {
        printf("Decimal\n");
        printf("=======\n");
        for (int i = address; i < length * s->unit_size; i++) {
            printf("%d", s->mem_buf[i]);
            if (i % s->unit_size == 0) {
                printf("\n");
            }
        }
    }
}
//начиная с этой функци надо доабвлять поверки на дебаг, про размеры,
// что я писал в начале в комменте
void saveIntoFile (state* s) {
    int sadrr, tl, length;
    if (!strcmp(s->file_name, "")) {
        printf("Error: file name is empty\n");
    }
    else {
        FILE *fd;
        if (!(fd = fopen(s->file_name, "r+"))) {
            printf("Error: file isnt opening\n");
        }
        else {
            printf("Please enter <source-address> <target-location> <length>\n");
            scanf("%x %x %d", &sadrr, &tl, &length);
            fseek(fd, tl, SEEK_SET);
            fwrite(s->mem_buf, s->unit_size, length, fd);
        }
    fclose(fd);
    }
}

void memoryModify (state* s) {
    if (!strcmp(s->file_name, "")) {
        printf("Error: file name is empty\n");
    }
    else {
        FILE *fd;
        if (!(fd = fopen(s->file_name, "r+"))) {
            printf("Error: file isnt opening\n");
        }
        else {
            int location, val;
            printf("Please enter <location> <val>\n");
            scanf("%x %x", &location, &val);
            if (s->debug_mode) {
                printf("location = %x\nval = %x\n", location, val);
            }
            fseek(fd, location, SEEK_SET);
            fwrite(&val, s->unit_size, sizeof(int), fd);
        }
    fclose(fd);
    }
}

void quit (state* s) {
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
    {"Set File Name", setFileName},
    {"Set Unit Size", setUnitSize},
    {"Load Into Memory", loadIntoMemory},
    {"Toggle Display Mode", toggleDisplayMode},
    {"Memory Display", memoryDisplay},
    {"Save Into File", saveIntoFile},
    {"Memory Modify",memoryModify},
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