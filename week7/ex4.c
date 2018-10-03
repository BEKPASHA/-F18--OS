#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t new_size, size_t old_size){
	void *new_ptr;
	if(ptr == NULL){
		ptr = malloc(new_size);
	}
	else if(new_size == 0){
		free(ptr);
	}
	else{
		new_ptr = malloc(new_size);
		if(new_size > old_size)
			memcpy(new_ptr, ptr, old_size);	
		else
			memcpy(new_ptr, ptr, new_size);
		free(ptr);
		ptr = new_ptr;
	}
}

int main(){

	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(n1 * sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	//Here I use my own realloc function called my_realloc
	a1 = my_realloc(a1, n2 * sizeof(int), n1 * sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	if(n2 > n1){
		for(i = n1; i < n2; i++){
			a1[i] = 0;
		}	
	}

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}
	printf("\n");
	
	free(a1);
	//Done with array now, done with program :D

	return 0;
}
