#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

int main(){

	int fd[2];
	char string[] = "Hello, world!\n";
	char buffer[100];
	pid_t childpid;

	pipe(fd);

	childpid = fork();

	if(childpid == 0){
		// if we are in child process
		write(fd[1], string, (strlen(string) + 1));
		close(fd[1]);
		exit(EXIT_SUCCESS); // exit child process
	} else{
		read(fd[0], buffer, sizeof(buffer));
		close(fd[0]);
		printf("Received string in parent process: %s", buffer);	
	}

	return 0;
}
