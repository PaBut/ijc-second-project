// htab_item_init.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_item_init function
// Creation and initialization of hashtable entry

#include "htab_private.h"

htab_item_t* htab_item_init(htab_key_t key){
    htab_item_t* item = malloc(sizeof(htab_item_t));
    if(item == NULL){
        return NULL;
    }

    item->pair = malloc(sizeof(htab_pair_t));
    if(item->pair == NULL){
        free(item);
        return NULL;
    }

    item->pair->key = malloc((strlen(key) + 1) * sizeof(char));
    if(item->pair->key == NULL){
        free(item->pair);
        free(item);
        return NULL;
    }

    item->next = NULL;
    strcpy((char*)item->pair->key, key);
    item->pair->value = 0;
    return item;
}