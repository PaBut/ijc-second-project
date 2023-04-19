// htab_item_free.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_item_free function
// Deallocates hashtable entry

#include "htab_private.h"

void htab_item_free(htab_item_t* item){
    free((char*)item->pair->key);
    free(item->pair);
    item->next = NULL;
    free(item);
}