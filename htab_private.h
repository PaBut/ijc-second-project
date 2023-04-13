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