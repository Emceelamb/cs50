#include <stdio.h>

void build_left(int num,int i, int j);
void build_right(int i, int j);
void build_space(void);
void build_pyramid(int num);

void main(void) {
  int num;
  printf("Enter a number: ");
  scanf("%i", &num);
  while (num<=0){
    printf("Invalid number: ");
    scanf("%i", &num);
  }

  build_pyramid(num);
}

void build_pyramid(int num){
  for(int i = 0; i <num; i++){
    for(int j = 0; j < num; j++){
      build_left(num, i, j);
    }

    build_space();

    for(int j= 0; j < num; j++){
      build_right(i, j);
    }
    printf("\n");
  }
}

void build_left(int num, int i, int j){
  if(j < num-i-1){
    printf(" ");
  }else {
    printf("#");
  }
}

void build_right(int i, int j){
  if(j < i+1){
    printf("#");
  }else {
    printf(" ");
  }
}

void build_space(void){
  printf("  ");
}

