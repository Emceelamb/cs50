#include <stdio.h>
#include <math.h>

long tenPow(int x);

int main(void){
  /* long num = 6176292929; */
  long num = 4003600000000014;
  long sum = 0;
  int second = 0;

  // This finds digit on CC
  /* sum = ((num%tenPow(2)) - (num % tenPow(1))) / tenPow(1); */

  for(int i = 1; i <= 15; i+=2) {
    // Step 1 -- Find every other digit starting with second to last
    // Multiply them by 2
    int mod =  (((num%tenPow(i+1)) - (num % tenPow(i))) / tenPow(i)) * 2;
    // This checks if the products are greater than ten
    // If so it will loop through the digits to add them
    if(mod>9){
      do{
        int r = mod % 10;
        if(mod%10==0){
         r = (mod % 100)/10;
         mod -= mod;
         sum+=r;
        } else {
          sum+=r;
          mod-=r;
        }
      } while (mod>0);
    } else {
      sum += mod;
    }
  }

  // This is finished Step 1
  //printf("%i, sum");

  // Step 2 is sum every other digits
  for(int i = 0; i <=15; i+=2){
    int mod = ((num % tenPow(i+1)) - (num % tenPow(i)))/tenPow(i); 
    second += mod;
  }
  printf("%i\n%i\n", sum, second);

  // Step 3 add two sums and check if last digit is 0
  if((second+sum)%10==0){
    printf("Digits are VALID!\n");
  } else {
    printf("Digits are INVALID!\n");
  }
}

// This function helps find the 
// the tens of the CC
long tenPow(int x){
  long long pow = 1;
  for (int i = 1; i <= x; i++){
    pow *= 10;
  }
  return pow;
}
