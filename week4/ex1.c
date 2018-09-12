#include <stdio.h>
#include <stdlib.h>
int main(void) {
int pid = fork(), n = 29;
if (pid > 0) { 
printf("Hello from parent [%d - %d]\n", pid, n);
} else if (pid == 0) { 
printf("Hello from child [%d - %d]\n", pid, n);
} else { 
return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}
