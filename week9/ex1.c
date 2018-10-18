#include <stdio.h>
#include <stdlib.h>
#define FRAMES 10
#define BITS_FOR_AGING 31
#define EMPTY_VAL -1
#define in 1

typedef int bool;
#define true 1
#define false 0

int p[FRAMES];
int a[FRAMES];

int main()
{
	FILE* fp = fopen("input.txt", "r");
	int i;
	for (i = 0; i < FRAMES; i++)
		p[i] = EMPTY_VAL;
	i = 0;
	int t = 0, miss = 0, j;
	
	while (fscanf(fp, "%d", &j) == in) {
		bool fault = true;
		int elder = 0;
		
		for (i = 0; i < FRAMES; i++) {
			if (p[i] == j) {
				a[i] = (1 << (BITS_FOR_AGING - 1)) & (a[i] >> 1);
				fault = false;
			} else {
				a[i] = a[i] >> 1;
			}
			if (a[i] < a[elder] || p[i] == EMPTY_VAL) 
				elder = i;
		}
		++t;
		if (!fault) continue;
		++miss;
		a[elder] = 1 << (BITS_FOR_AGING - 1);
		p[elder] = j;				
	}	 
	printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", FRAMES, t, t - miss, miss);
	printf("hits/miss => %.2f\n", (double)(t-miss)/(miss));	
	return 0;
}
