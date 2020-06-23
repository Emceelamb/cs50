package main

import "fmt"


func main(){

    // Algorithm
    // index = 0.0588 * L - 0.296 * S - 15.8

    text := "Would you like them here or there? I would not like them here or there. I would not like them anywhere.";

    letters := get_character(text)
    fmt.Println(letters)
    words := get_words(text)
    fmt.Println(words)
    sentences := get_sentences(text)
    // // index = 0.0588 * L - 0.296 * S - 15.8

    L := float64 (letters) / float64 (words) * 100
    S := float64 (sentences) / float64 (words) * 100
    index := 0.0588 * L - 0.296 * S - 15.8
    fmt.Printf("Grade %d\n", int(index))
}

func get_character(str string) int{
    char_count := 0;
    length_of_string := len(str);
    for i :=0; i < length_of_string; i++ {
        if ((str[i] >=65 && str[i] <= 90) ||
        (str[i] >= 97 && str[i] <= 122)){
            char_count++;
        }
    }

    return char_count;
}

func get_words(str string) int{
    word_count := 1
    length_of_string := len(str);
    for i := 0; i < length_of_string; i++{
        if(str[i] == 32){
            word_count++;
        }
    }

    return word_count;
}

func get_sentences(str string) int{
    sentence_count := 0;
    length_of_string := len(str)
    for i :=0; i < length_of_string; i++{
        if(str[i] == 46 || str[i] == 63 || str[i] == 33){
            sentence_count++;
        }
    }

    return sentence_count;
}
