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