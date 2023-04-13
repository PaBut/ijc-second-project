#include "htab_private.h"

void htab_free(htab_t * t){
    if(t == NULL){
        return;
    }
    htab_clear(t);
    if(t->arr_ptr != NULL){
        free(t->arr_ptr);
    }
    free(t);
}