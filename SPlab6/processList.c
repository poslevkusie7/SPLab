#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#include "processList.h"

/*
How can I do anything with linked list if there is no element 
or begin of linked list? whats the meaning of process_list?
*/


void addProcess(process** process_list, cmdLine* cmd, pid_t pid) {
    process *tmp = process_list;
    tmp = (struct process *)malloc(sizeof(struct process));
    tmp->cmd = cmd;
    tmp->pid = pid;
    tmp = tmp->next;
}

/*
How will operate extencion in my shell (like we dont have 
a process list there, so here, some imagintion) and how will
it work if u say that we dont touch my shell program.
*/
void printProcessList(process** process_list) {
    process *tmp = process_list;
    while (tmp != NULL) {
        printf("PID\t Command\t STATUS\n %d\t %s\t %d\n", tmp->pid, tmp->cmd->arguments[0], tmp->status);
        tmp = tmp ->next;
    }
    
}


void freeProcessList(process* process_list) {
    free(process_list);
}

int main () {
    return 0;
}