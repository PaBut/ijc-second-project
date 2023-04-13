//#include <stdint.h>
// #include <stdlib.h>
#include "htab_private.h"
// #include "htab.h"

htab_t *htab_init(const size_t n){
    struct htab* tab = /*(struct htab*)*/malloc(sizeof(struct htab));
    if(tab == NULL){
        return NULL;
    }
    tab->size = n;
    tab->arr_size = 0;
    tab->arr_ptr = malloc(n * sizeof(htab_item_t*));
    if(tab->arr_ptr == NULL){
        free(tab);
        return NULL;
    }
    for(size_t i = 0; i < tab->size; i++){
        tab->arr_ptr[i] = NULL;
    }

    return tab;
}