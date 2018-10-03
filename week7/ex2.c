#include <stdio.h>
#include <stdlib.h>

int main(){

	printf("Enter number of elements in array: \n");
	int N;
	scanf("%d", &N);
	int *array = malloc(N * sizeof(int));
	int i;
	for (i = 0; i < N; i++){
		array[i] = i;
		printf("%d ", array[i]);
	}
	printf("\n");
	free(array);
	return 0;
}
