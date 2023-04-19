// htab_lookup_add.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_lookup_add function
// Appends an entry if it won't be found based on key

#include "htab_private.h"
#include <string.h>

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    if(t == NULL || t->arr_ptr == NULL){
        return NULL;
    }
    htab_pair_t* pair = htab_find(t, key);
    if(pair == NULL){
        size_t index = htab_hash_function(key) % t->arr_size;
        htab_item_t* new_item = htab_item_init(key);
        if(new_item == NULL){
            return NULL;
        }
        htab_item_t* list_item = t->arr_ptr[index];
        if(list_item == NULL){
            t->arr_ptr[index] = new_item;
        }
        else{
            for(;list_item->next != NULL; list_item = list_item->next);
            list_item->next = new_item;
        }
        t->size++;
        pair = new_item->pair;
    }
    return pair;
}