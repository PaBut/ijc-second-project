//#include <stdint.h>
// #include <stdlib.h>
#include "htab_private.h"

htab_t *htab_init(const size_t n){
    struct htab* tab = malloc(sizeof(struct htab));
    if(tab == NULL){
        return NULL;
    }
    tab->arr_size = n;
    tab->size = 0;
    htab_item_t** items = malloc(n * sizeof(htab_item_t*));
    if(items == NULL){
        free(tab);
        return NULL;
    }
    tab->arr_ptr=items;
    return tab;
}