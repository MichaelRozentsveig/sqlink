#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 

int main() 
{ 
	int fd1[2]; 
	int fd2[2]; 

	char str2[] = "Bye"; 
	char str1[] = "Hi";
	pid_t p; 

	pipe(fd1);
	pipe(fd2);
 
	p = fork();

	/* Parent */
	if (p > 0) 
	{ 
		close(fd1[0]); 
 
		write(fd1[1], str1, 3); 
		close(fd1[1]); 

		wait(NULL); 

		close(fd2[1]);

		read(fd2[0], str2, 4); 
		printf("Child answered: %s\n", str2); 
		close(fd2[0]); 
	} 

	/* Child */ 
	else
	{ 
		close(fd1[1]);  

		read(fd1[0], str1, 3); 

		printf("Father says: %s\n",str1);
		close(fd1[0]); 
		close(fd2[0]); 

		write(fd2[1], str2, 4); 
		close(fd2[1]); 

		exit(0); 
	} 
} 
