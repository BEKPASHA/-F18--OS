#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char Str[100];

  scanf("%s", Str);
  
  char temp;   
  int str_size = strlen(Str);   
  for(int i=0; i<str_size/2; i++) {
    temp = Str[str_size-1-i];
    Str[str_size-1-i] = Str[i];
    Str[i] = temp;
  }

  puts(Str);
  return 0;
}
