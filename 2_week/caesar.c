#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int checkDec(char array[]);
int shift(int letter, int key);

int main(int argc, char *argv[]){
    // Check if arg
    if (argc == 2) {
        printf("SUCCESS\n");
    } else {
        printf("ERROR: NO VALID KEY\n");
        printf("Usage: ./caesar key\n");
    }

    // if arg is it digit
    int key = checkDec(argv[1]);
    // convert arg to digit
    printf("key: %i\n", key);

    // Ask for msg
    string s = get_string("Enter your message: ");
    // printf("%s\n", s);
    // Loop through msg
    int str_len = strlen(s);
    for(int i = 0; i<=str_len;i++){
        int lettr = shift(s[i], key);
        printf("%c", lettr ); 
    }

    // //if letter is upper case rotate

    // //if letter is

    // // if else print as is

    // print new line
    printf("\n");


}

// check if valid number
int checkDec(char array[]){
    int length = 0;
    int input_len = strlen(array);
    for(int i = 0; i < input_len; i++){
        if((int) array[i] < 48 || (int) array[i] > 57){
            printf("NOT A VALID key\n");
            return -1;
        }
    }
    return (int) atoi(array);
}

// ci = (pi + k) % 26



int shift(int letter, int key){
    int shifted_letter = 0;
    int new_key = key;
    if (letter >=65 && letter <= 90){
        shifted_letter = (((letter - 65)+key)%26) + 65;
    } else if (letter >= 97 && letter <=122){
        shifted_letter = (((letter - 97) + key)%26) + 97;
    } else {
        shifted_letter = letter;
    }

    return shifted_letter;
}
