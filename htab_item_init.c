#include "htab_private.h"

htab_item_t* htab_item_init(htab_key_t key){
    htab_item_t* item = malloc(sizeof(htab_item_t));
    if(item == NULL){
        return NULL;
    }
    item->pair = malloc(sizeof(htab_pair_t));
    if(item->pair == NULL){
        free(item);
        return NULL;
    }
    item->next = NULL;
    item->pair->key = key;
    return item;
}