// htab_private.h
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Structure declaratios of hashtable and its entry

#include <stdint.h>
#include <stdlib.h>
#include "htab.h"

typedef struct htab_item{
    htab_pair_t* pair;
    struct htab_item* next;
} htab_item_t;

struct htab{
    size_t size;
    size_t arr_size;
    htab_item_t** arr_ptr;
};

htab_item_t* htab_item_init(htab_key_t key);
void htab_item_free(htab_item_t* item);