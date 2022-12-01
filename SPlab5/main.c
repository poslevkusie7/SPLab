#include "util.h"
#include <unistd.h>
#include <sys/syscall.h>

#define SYS_WRITE 4
#define STDOUT 1
#define SYS_OPEN 5
#define O_RDWR 2
#define SYS_SEEK 19
#define SEEK_SET 0
#define SHIRA_OFFSET 0x291

extern int system_call();

int main (int argc , char* argv[], char* envp[])
{
  /*Complete the task here*/
  for (int i = 1; i < argc; i++) {
    syscall(4, 1, argv[i], sizeof(argv[i]) - 1);
    syscall(4, 1, " ", sizeof(char));
  }
    syscall(4, 1, "\n", sizeof(char));
  return 0;
}