#include <stdio.h>
#include <math.h>

void main(void){
  float input;
  int coins = 0;;
  int cents;
  printf("Input floating number: ");
  scanf("%f",&input);

  cents = input * 100;
  printf("$%.2f is equal to %i cents.\n", input, cents);

  do {
    if (cents - 25>=0){
      cents -= 25;
      printf("Quarter added. Cents left: %i\n", cents);
      coins++;
    }
    else if(cents - 10>=0){
      printf("Dime added, Cents left: %i\n", cents);
      cents -= 10;
      coins++;
    }
    else if(cents - 5>=0){
      printf("Nickle added. Cents left: %i\n", cents);
      cents -= 5;
      coins++;
    }  
    else if(cents - 1>=0){
      printf("Penny added. Cents left: %i\n", cents);
      cents -= 1;
      coins++;
    }  
   }while (cents > 0);

  printf("Total coins: %i\n", coins);
}
