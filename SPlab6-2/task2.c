#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void err(char *str, int num) {
    if (num == -1) 
        fprintf(stderr, "%s\n", str);       
    else
        fprintf(stderr, "%s %d\n", str, num); 
}


int main (int argc, char **argv) {
    int dFlag = 0;
    int pip[2], s1, s2;
    int pid1, pid2;
    
    if ((argc > 1) && (!strcmp(argv[1], "-d"))) 
        dFlag = 1;
    if (pipe(pip) < 0) 
        exit(1);


    if (dFlag) 
        err("parent_process>forking…", -1);
    pid1 = fork();
    if (dFlag) 
        err("parent_process>created process with id: ", pid1);
    if (pid1 == 0) {
        fclose(stdout);
        if (dFlag) 
            err("child1>redirecting stdout to the write end of the pipe…", -1);
        int copy_output = dup(pip[1]);
        close(pip[1]);
        if (dFlag) 
            err("child1>going to execute cmd: ls -l", -1);
        char * command = "ls";
        char * argument_list[] = {"ls", "-l", NULL};
        execvp(command, argument_list);
        exit(1);
    }


    if (dFlag) 
        err("parent_process>closing the write end of the pipe…", -1);
    close(pip[1]);


    if (dFlag) 
        err("parent_process>forking…", -1);
    pid2 = fork();
    if (dFlag) 
        err("parent_process>created process with id: ", pid2);
    if (pid2 == 0) {
        fclose(stdin);
        if (dFlag) 
            err("child2>redirecting stdin to the read end of the pipe…", -1);
        int copy_input = dup(pip[0]);
        close(pip[0]);
        if (dFlag) 
            err("child2>going to execute cmd: tail -n 2", -1);
        char * command = "tail";
        char * argument_list[] = {"tail", "-n", "2", NULL};
        execvp(command, argument_list);
        exit(1);
    }

    
    if (dFlag) 
        err("parent_process>closing the read end of the pipe…", -1);
    close(pip[0]);
    if (dFlag) 
        err("parent_process>waiting for child processes to terminate…", -1);
    waitpid(pid1, &s1, 0);
    waitpid(pid2, &s2, 0);
    if (dFlag) 
        err("parent_process>exiting…", -1);
    return 0;
}