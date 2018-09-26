#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int stop = 1;

void sigkill_handler (int signo) {
	/* your signal handler code */
	printf("\nProgram killed\n");
	exit(EXIT_SUCCESS);
}

void sigstop_handler (int signo) {
	/* your signal handler code */
	printf("Program stopped\n");
	stop = 1;
	while(stop){
		sleep(1);
	}
}

void sigcontinue_handler(int signo){
	stop = 0;
	printf("Program continue its work\n");
}

void sigusr1_handler (int signo) {
	/* your signal handler code */
	printf("User defined signal handler\n");
}


int main (void) {
	/* set signal handler here */
	/* what for signal from user */
	signal(SIGKILL, sigkill_handler);
 	signal(SIGSTOP, sigstop_handler);
 	signal(SIGUSR1, sigusr1_handler);
 	signal(SIGCONT, sigcontinue_handler);
	while (1){	
 		sleep (0.5);
	}
 
	return EXIT_SUCCESS;
}
