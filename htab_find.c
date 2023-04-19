// htab_find.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_find function
// for getting entry with specified key

#include "htab_private.h"
#include <string.h>

htab_pair_t * htab_find(const htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % t->arr_size;
    if(t->arr_ptr[index] == NULL){
        return NULL;
    }
    for(htab_item_t *item = t->arr_ptr[index]; item != NULL; item = item->next){
        if(!strcmp(item->pair->key, key)){
            return item->pair;
        }
    }
    return NULL;
}