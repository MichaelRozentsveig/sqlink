#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid>0)
    {
        wait(&pid);
        printf("End of program\n");
    }
    else
    {
        execv("check", NULL);
    }
}