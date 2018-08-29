// Preprocessor directives requesting to include the necessary header files
#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(int argc, char *argv[]) {
 double z = DBL_MAX;  // assign the values  
 float y = FLT_MAX; 
 int x = INT_MAX;          
  printf("Integer size: %lu\nFloat size: %lu\nDouble size: %lu\n", sizeof(x), sizeof(y), sizeof(z)); // print the values 
  printf("Max integer: %d\nMaximum float: %f\nMaximum double: %lf\n", x, y, z); // print the values 
  return 0;
}
