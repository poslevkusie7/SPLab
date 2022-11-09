#include <stdio.h>

int main () {
    //FILE *fp =  fopen("file.txt","r");
    char c;
    while (scanf("%c", &c) == 1) {
        //c = fgetc(fp);
        //if (c == feof()) { break; }
        if ('a' <= c && c <= 'z') {
            c += 'A' - 'a';
        }
        printf("%c", c);
        
    }
   //fclose(fp);
   return 0;
}

