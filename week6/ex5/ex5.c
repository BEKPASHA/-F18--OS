#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (void) {
	
	pid_t pid = fork();

	if(pid == 0){
		// if we are in child process
		while(1){
			printf("I’m alive\n");
			sleep(1);
		}
	} else{
		// if we are in parent process
		sleep(10);
		printf("Parent process sends SIGTERM signal to child\n");
		kill(pid, SIGTERM);
	}	
	return EXIT_SUCCESS;
}
