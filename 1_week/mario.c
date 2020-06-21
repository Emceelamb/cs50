#include <stdio.h>

void build_left(int num);
void build_right(int num);

void main(void) {
  int num;
  printf("Enter a number: ");
  scanf("%i", &num);
  build_left(num);
}

void build_left(int num){
  for(int i = 0; i <num; i++){
    for(int j = 0; j < num; j++){
      if(j < num-i){
        printf(" ");
      }else {
        printf("#");
      }
    }
    printf("\n");
  }
}

void build_right(int num){
  for(int i = 0; i <num; i++){
    for(int j = 0; j < num; j++){
      if(j < i+1){
        printf("#");
      }else {
        printf(" ");
      }
      
    }
    printf("\n");
  }
}
