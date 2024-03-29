#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

int handle_error(int ret) 
{
	if(ret==-1) 
    {
		int myerrno=errno;
		fprintf(stderr, "there was an error from a system call\n");
		fprintf(stderr, "the error was [%s]\n", strerror(myerrno));
		exit(-1);
		return -1;
	} else 
    
    {
		return ret;
	}
}

int main(int argc, char** argv, char** envp) {
	printf("You will see this once...\n");
	printf("The parent pid is %d\n", getpid());

	int need_to_run_child = 1;

	while(need_to_run_child) 
    {
		pid_t child_pid=handle_error(fork());
		if(child_pid) 
        {
			printf("This is the parent\n");
			printf("The child pid is %d\n", child_pid);
			int status;
			handle_error(wait(&status));
			if(WIFEXITED(status)) 
            {
				need_to_run_child = 0;
			} else 
            {
				fprintf(stderr, "Oops, the child died abnormaly and the signal with which it was killed was %d\n", WTERMSIG(status));
			}
		} 
        else 
        {
			printf("This is the child\n");
			sleep(10);
			*(char*)0=0;
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}