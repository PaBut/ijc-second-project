#include "htab_private.h"
#include <string.h>

bool htab_erase(htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % t->size;
    if(t->arr_ptr[index] == NULL){
        return false;
    }
    for(htab_item_t* item = t->arr_ptr[index]; item->next != NULL; item = item->next){
        if(!strcmp(item->next->pair->key, key)){
            htab_item_t* item_to_delete = item->next;
            item->next = item_to_delete->next;
            htab_item_free(item_to_delete);
            t->arr_size--;
            return true;
        }
    }
    return false;
}