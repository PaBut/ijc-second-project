// htab_clear.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_clear function
// for deleting all entries in hashtable

#include "htab_private.h"

void htab_clear(htab_t * t){
    for(size_t i = 0; i < t->arr_size; i++){
        while(t->arr_ptr[i] != NULL){
            htab_item_t* item_to_delete = t->arr_ptr[i];
            t->arr_ptr[i] = t->arr_ptr[i]->next;
            htab_item_free(item_to_delete);
        }
    }
    t->size = 0;
}