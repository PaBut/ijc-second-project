// htab_for_each.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_for_each function
// calls the function on each entry

#include "htab_private.h"
#include <string.h>

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    if(t == NULL || t->arr_ptr == NULL ||
     t->size == 0 || f == NULL){
        return;
    }
    for(size_t i = 0; i < t->arr_size; i++){
        if(t->arr_ptr[i] != NULL){
            for(htab_item_t* item = t->arr_ptr[i]; item != NULL; item = item->next){
                f(item->pair);
            }
        }
    }
}