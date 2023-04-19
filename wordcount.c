// wordcount.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Prints the number of times words appeared in the text

#include "htab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

#define MAX_WORD_LENGTH 255
#define HTAB_SIZE 1500

void print_count(htab_pair_t* pair){
    printf("%s\t%d\n", pair->key, pair->value);
}

int main(){
    struct htab* tab = htab_init(HTAB_SIZE);
    if(tab == NULL){
        return EXIT_FAILURE;
    }
    char* word = malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
    if(word == NULL){
        htab_free(tab);
        return EXIT_FAILURE;
    }
    int length = 0;
    do{
        length = read_word(word, MAX_WORD_LENGTH, stdin);
        if(strlen(word) > 0){
            htab_pair_t* pair = htab_lookup_add(tab, word);
            if(pair == NULL){
                free(word);
                htab_free(tab);
                return EXIT_FAILURE;
            }
            pair->value++;
        }
        
    }while(length != EOF);

    htab_for_each(tab, &print_count);
    #ifdef STATISTICS
    htab_statistics(tab);
    #endif
    htab_free(tab);
    free(word);

    return EXIT_SUCCESS;
}