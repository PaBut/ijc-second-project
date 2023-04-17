#include "htab_private.h"

void htab_item_free(htab_item_t* item){
    free((char*)item->pair->key);
    free(item->pair);
    item->next = NULL;
    free(item);
}