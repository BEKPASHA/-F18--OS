#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>

int main(){

	time_t start = time(NULL);
	int i = 1;
  
	while((time(NULL) - start) < 10){
		int num = 1024 * 10 * sizeof(char);
		void * pointer = malloc(num); // allocate 10 MB
		memset(pointer, '0', num);
		printf("%d second\n", i);
		i++;
		sleep(1);
	}

	return 0;
}
