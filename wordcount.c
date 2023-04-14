#include "htab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

#define MAX_WORD_LENGTH 255

void print_count(htab_pair_t* pair){
    printf("%s\t%d\n", pair->key, pair->value);
}

int main(){
    struct htab* tab = htab_init(1000);
    if(tab == NULL){
        return EXIT_FAILURE;
    }
    char* word = malloc((MAX_WORD_LENGTH + 1) * sizeof(char));
    if(word == NULL){
        htab_free(tab);
        return EXIT_FAILURE;
    }
    // while(scanf("%255s", word) != EOF){
    //     char* key = malloc((strlen(word) + 1) * sizeof(char));
    //     if(word == NULL){
    //         return EXIT_FAILURE;
    //     }
    //     strcpy(key, word);
    //     htab_lookup_add(tab, key)->value++;
    // }

    int length = 0;
    do{
        length = read_word(word, MAX_WORD_LENGTH + 1, stdin);
        // if(length > MAX_WORD_LENGTH){
        //     length = MAX_WORD_LENGTH;
        // }
        char* key = malloc((strlen(word) + 1) * sizeof(char));
        if(key == NULL){
            free(word);
            htab_free(tab);
            return EXIT_FAILURE;
        }
        strcpy(key, word);
        htab_pair_t* pair = htab_lookup_add(tab, key);
        if(pair == NULL){
            free(key);
            free(word);
            htab_free(tab);
            return EXIT_FAILURE;
        }
        pair->value++;
    }while(length != EOF);
    htab_for_each(tab, print_count);
    htab_free(tab);
    free(word);

    return EXIT_SUCCESS;
}