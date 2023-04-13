#include "htab_private.h"
#include <string.h>

void htab_for_each(/*const*/ htab_t * t, void (*f)(htab_pair_t *data)){
    if(t == NULL || t->arr_ptr == NULL || f == NULL){
        return;
    }
    for(size_t i = 0; i < t->size; i++){
        if(t->arr_ptr[i] != NULL){
            for(htab_item_t* item = t->arr_ptr[i]; item != NULL; item = item->next){
                htab_key_t key = item->pair->key;
                f(item->pair);
                if(strcmp(key, item->pair->key)){
                    strcpy((char*)item->pair->key, key);
                }
            }
        }
    }
}