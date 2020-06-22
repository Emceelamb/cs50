#include <stdio.h>
#include <cs50.h>
#include <string.h>

int get_character(char array[]);
int get_words(char array[]);
int get_sentences(char array[]);

int main(void){

    // Algorithm
    // index = 0.0588 * L - 0.296 * S - 15.8

    string text = "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";

    int letters = get_character(text);
    int words = get_words(text);
    int sentences = get_sentences(text);
    // index = 0.0588 * L - 0.296 * S - 15.8

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int index = 0.0588 * L - 0.296 * S - 15.8;
    printf("Grade %i\n", index);
}

int get_character(char array[]){
    int char_count = 0;
    int length_of_string = strlen(array);
    for(int i =0; i < length_of_string; i++){
        if ((array[i] >=65 && array[i] <= 90) ||
        (array[i] >= 97 && array[i] <= 122)){
            char_count++;
        }
    }

    return char_count;
}

int get_words(char array[]){
    int word_count = 1;
    int length_of_string = strlen(array);
    for(int i =0; i < length_of_string; i++){
        if(array[i] == 32){
            word_count++;
        }
    }

    return word_count;
}

int get_sentences(char array[]){
    int sentence_count = 0;
    int length_of_string = strlen(array);
    for(int i =0; i < length_of_string; i++){
        if(array[i] == 46 || array[i] == 63 || array[i] == 33){
            sentence_count++;
        }
    }

    return sentence_count;
}
