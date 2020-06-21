#include <stdio.h>

void main(void) {

  int num;

  printf("Please enter a number: ");
  scanf("%i", &num);

  if(num < 0){
    printf("Please enter a number: ");
    scanf("%i", &num);
  }

  for(int x = 0; x < num; x++){
    for(int x = 0; x < num; x++){
      printf("# ");
    }
    printf("\n");
  }
}

