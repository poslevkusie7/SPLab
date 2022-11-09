#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h> 
#include <fcntl.h>  

int main (int argc, char **argv) {
    char c;
    int adrr;
   int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC | O_EXCL, 0777);
    if (argc == 2) {        
        while (scanf("%c", &c) == 1) {
            write(fd, &c, 1);
            adrr = (int)c;
            fprintf(stderr, "%x ", c);
            if ('a' <= c && c <= 'z') {
                c += 'A' - 'a';
            } 
            adrr = (int)c;
            fprintf(stderr, "%x\n", c);
        }
        while(read(fd, &c, 1)) {
            printf("%c", c);
        }
       
        
    }
    else {
        while (scanf("%c", &c) == 1) {
        
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        printf("%c", c);
    }
    }
   return 0;
}




/*
int main (int argc, char **argv) {
    char c;
    int fd;
    int adrr;
    while (scanf("%c", &c) == 1) {
        if (argc == 2) {
        adrr = (int)c;
        printf("%x ", adrr);
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        } 
        adrr = (int)c;
        printf("%x\n", c);
        }
        write(fd, &c, 1);
    }
    while(read(fd, &c, 1))
    {
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        printf("%c", c);
    }
    return 0;
}
*/