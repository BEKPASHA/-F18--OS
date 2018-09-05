#include <stdio.h>
#include <stdlib.h>
void bubble_sort_pointers(int* array, int n) {
    int i;
    for (i = 1; i < n; i++) {
       int j;
       for (j = i; j > 0; j--) {
           if (arr[j] < array[j - 1]) {
               swap(array + j, arr + j - 1); }} }}

int main() {
    int n;
    scanf("%d", &n);
    
    int *array = (int*) malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }    
     bubble_sort_pointers(array, n);
    
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
