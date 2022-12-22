#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>


#include "LineParser.h"

#define PATH_MAX 4096
#define INPUTSIZE 2048

void execute(cmdLine *pCmdLine, int dFlag);

void handler(int sig);

int do_cd(int argc, char * const argv[MAX_ARGUMENTS]);


void execute(cmdLine *pCmdLine, int dFlag) {
    do {
        if (!strcmp(pCmdLine->arguments[0], "cd")) {
                do_cd(pCmdLine->argCount, pCmdLine->arguments);
                //fprintf(stderr, "CD dead\n"); 
                if (dFlag) {
                    fprintf(stderr, "ex.c. = %s\n", pCmdLine->arguments[0]);
                }
        }
        else {

            int status;
            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                _exit(EXIT_FAILURE);
            }

            if (pid == 0) {

                if (pCmdLine->inputRedirect != NULL) {
                    int fd = open(pCmdLine->inputRedirect, O_RDONLY);
                    dup2(fd, 0);
                    close(fd);
                }
                if (pCmdLine->outputRedirect != NULL) {
                    int fd = open(pCmdLine->outputRedirect, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                    dup2(fd, 1);
                    close(fd);
                }

                execvp(pCmdLine->arguments[0], pCmdLine->arguments);
                perror("Execv dnt work");
                _exit(1);
            }

            if (dFlag) {
                fprintf(stderr, "stderr: pid = %d \n", pid); 
                fprintf(stderr, "ex.c. = %s\n",pCmdLine->arguments[0]);
            }

            if (pCmdLine->blocking) {
                do {
                    waitpid(pid, &status, WUNTRACED | WCONTINUED);
                    if (WIFEXITED(status)) {
                        printf("exited, status=%d\n", WEXITSTATUS(status));
                    } else if (WIFSIGNALED(status)) {
                        printf("killed by signal %d\n", WTERMSIG(status));
                    } else if (WIFSTOPPED(status)) {
                        printf("stopped by signal %d\n", WSTOPSIG(status));
                    } else if (WIFCONTINUED(status)) {
                        printf("continued\n");
                    }
                } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            }
            
        }

        pCmdLine = pCmdLine->next;

    } while (pCmdLine != NULL);

}


void handler(int sig)
{
	printf("\nRecieved Signal : %s\n", strsignal(sig));
	if (sig == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
	}
	else if (sig == SIGCONT)
	{
		signal(SIGCONT, SIG_DFL);
	}
	signal(sig, SIG_DFL);
	raise(sig);
}


int do_cd(int argc, char * const argv[MAX_ARGUMENTS]) {
	const char *	path;
	char newdir[PATH_MAX];

	if (argc > 1)
		path = argv[1];
	else
	{
		path = getenv("HOME");

		if (path == NULL)
		{
			fprintf(stderr, "No HOME environment variable\n");

			return 1;
		}
	}

	if (chdir(path) < 0)
		perror(path);
	

	getcwd(newdir, PATH_MAX);
	printf("pwd: %s\n", newdir);

	return 0;
}


void printCmdLine (cmdLine *cmd) {
    printf("argcCount = %d: ", cmd->argCount);
    for (int i = 0; i < cmd->argCount; i++) {
        printf("arguments[%i] = %s, ", i, cmd->arguments[i]);
    }
    printf("redirect_o = %s\n", cmd->outputRedirect);
}

int main (int argc, char **argv) {
    int dFlag = 0;
    if ((argc > 1) && (!strcmp(argv[1], "-d"))) { dFlag = 1; }
    char cwd[PATH_MAX];
    if (getcwd(cwd, PATH_MAX) == NULL)
        perror("getcwd() error");

    else
        printf("Current working directory is: %s\n", cwd);
    
    char input[INPUTSIZE];

    printf("Starting the program\n");
	signal(SIGINT, handler);
	signal(SIGTSTP, handler);
	signal(SIGCONT, handler);

    while(fgets(input, INPUTSIZE , stdin)) {
        if (strstr(input, "quit")) {break;}
        //if (strstr(input, "procs")) {}

        cmdLine * cmd = parseCmdLines(input);

        execute(cmd, dFlag);

        freeCmdLines(cmd);
    }

    
    return 0;
}