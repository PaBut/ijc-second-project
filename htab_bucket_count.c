// htab_bucket_count.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_bucket_count function
// for getting hashtable size

#include "htab_private.h"

size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}
