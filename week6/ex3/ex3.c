#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler (int signo) {
	/* your signal handler code */
	printf("\nExit program\n");
	exit(EXIT_SUCCESS);
}

int main (void) {
	/* set signal handler here */
	/* what for signal from user */
	while (1){
 		signal(SIGINT, sig_handler);
 		sleep (1);
	}
 
	
