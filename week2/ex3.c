#include <stdio.h>
int main(void) {
  int s;
  scanf("%d", &s);
  for (int i=0; i<s; i++) {
    for (int k=0; k<(s-i-1); k++) {
      printf(" ");
    }
    for (int j=0; j<=(2*i); j++) {
      printf("*");
    }
    for (int z=0; z<(s-i); z++) {
      printf(" ");
    }
     printf("\n");
  }
  return 0;
}
