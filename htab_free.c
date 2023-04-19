// htab_free.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_free function
// deallocates hashtable(destructor)

#include "htab_private.h"

void htab_free(htab_t * t){
    if(t == NULL){
        return;
    }
    htab_clear(t);
    free(t->arr_ptr);
    free(t);
}