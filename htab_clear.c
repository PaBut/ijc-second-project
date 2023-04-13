#include "htab_private.h"

void htab_clear(htab_t * t){
    if(t->arr_ptr == NULL || t == NULL){
        return;
    }
    for(size_t i = 0; i < t->size; i++){
        for(htab_item_t* item = t->arr_ptr[i]; item->next != NULL; item = item->next){
            htab_item_t* item_to_delete = item;
            t->arr_ptr[i] = item->next;
            htab_item_free(item_to_delete);
        }
    }
    t->arr_size = 0;
}