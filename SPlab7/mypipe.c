#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

  
int main(void)
{
    char* msg1 = "hello, world #1";

    char inbuf[MSGSIZE];
    int p[2], pid, nbytes;
  
    if (pipe(p) < 0)
        exit(1);
    pid = fork();
    if (pid == 0) {
        close(p[0]);
        write(p[1], msg1, MSGSIZE);
        close(p[1]);
        //wait(NULL);
    }

    close(p[1]);
    while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
        printf("%s\n", inbuf);
    if (nbytes != 0)
        exit(2);
    close(p[0]);
    return 0;
}