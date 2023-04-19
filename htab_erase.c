// htab_erase.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_erase function
// for deleting entry with specified key

#include "htab_private.h"
#include <string.h>
#include <stdio.h>

bool htab_erase(htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % t->arr_size;
    if(t->arr_ptr[index] == NULL){
        return false;
    }
    htab_item_t* item = t->arr_ptr[index];
    if(!strcmp(item->pair->key, key)){
        htab_item_t* item_to_delete = item;
        t->arr_ptr[index] = item_to_delete->next;
        htab_item_free(item_to_delete);
        t->size--;
        return true;
    }
    for(; item->next != NULL; item = item->next){
        if(!strcmp(item->next->pair->key, key)){
            htab_item_t* item_to_delete = item->next;
            item->next = item_to_delete->next;
            htab_item_free(item_to_delete);
            t->size--;
            return true;
        }
    }

    return false;
}