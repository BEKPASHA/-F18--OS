#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (void) {
	
	int fd[2];
	pipe(fd);

	pid_t pid1 = fork();

	if(pid1 == 0){
		// if we are in child process
		printf("1-st child begins its work\n");
		pid_t pid_of_other_child;
		read(fd[0], &pid_of_other_child, sizeof(pid_of_other_child));
		close(fd[0]);
		sleep(3);
		printf("1-st child sends SIGSTOP signal to 2-nd one\n");
		kill(pid_of_other_child, SIGSTOP);
		exit(EXIT_SUCCESS);	

	} else{
		// if we are in parent process
		pid_t pid2 = fork();

		if(pid2 == 0){
			// if we are in child process
			
			printf("2-nd child begins its work\n");
			while(1){
				printf("2-nd process: I am alive\n");
				sleep(1);
			}
			exit(EXIT_SUCCESS);			
		} else{
			// if we are in parent process
			
			printf("parent process send pid of second child to first\n");
			write(fd[1], &pid2, sizeof(pid2));
			close(fd[1]);	
			printf("parent process waits for state changes in second child \n");
			int status;
			waitpid(pid2, &status, WUNTRACED);
			printf("parent process resumed work \n");
		}
	}

 	
	return EXIT_SUCCESS;
}
