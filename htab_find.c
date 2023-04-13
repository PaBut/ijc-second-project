#include "htab_private.h"
#include <string.h>

htab_pair_t * htab_find(const htab_t * t, htab_key_t key){
    size_t index = htab_hash_function(key) % t->size;
    for(htab_item_t *item = t->arr_ptr[index]; item != NULL; item = item->next){
        if(!strcmp(item->pair->key, key)){
            return item->pair;
        }
    }
    return NULL;
}