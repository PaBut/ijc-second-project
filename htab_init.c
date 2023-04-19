// htab_init.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_init function
// table creation and initialization(constructor)

#include "htab_private.h"

htab_t *htab_init(const size_t n){
    struct htab* tab = malloc(sizeof(struct htab));
    if(tab == NULL){
        return NULL;
    }
    tab->size = 0;
    tab->arr_size = n;
    tab->arr_ptr = malloc(n * sizeof(htab_item_t*));
    if(tab->arr_ptr == NULL){
        free(tab);
        return NULL;
    }
    for(size_t i = 0; i < tab->arr_size; i++){
        tab->arr_ptr[i] = NULL;
    }

    return tab;
}