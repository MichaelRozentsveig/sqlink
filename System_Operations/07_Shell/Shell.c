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
        execv("check", (char*)NULL);
    }
}

while(1)
{
    printf("->");
    scanf("%s",buffer);

    if (strcmp(buffer,"exit") == 0);
        return 0;

    arg[0] = buffer;

    pid = fork();

    if (pid == -1)
    {
        printf("Error in fork!\n");
    }
}