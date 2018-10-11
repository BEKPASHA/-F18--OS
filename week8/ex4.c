#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main(){

	time_t start = time(NULL);
	int second = 1;
	struct rusage r;

	while((time(NULL) - start) < 10){
		int mem_size = 1024 * 10 * sizeof(char);
		void * pointer = malloc(mem_size); // allocate 10 MB
		memset(pointer, 0, mem_size); // fill allocated memory with 0
		getrusage(RUSAGE_SELF, &r); 
		printf("%d second, Memory usage = %ld\n", second, r.ru_maxrss);
		// rest of fields as ixrss, isrss, idrss does not supported by our OS
		// that is why I used maxrss 
		second++;
		sleep(1);
	}

	return 0;
}
