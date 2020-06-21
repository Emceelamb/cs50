#include <stdio.h>

void main(void){

  char str[20];
  printf("Whats your name?\n");
  scanf("%[^\n]%*c", str);
  printf("Hello, %s\n", str);

}
