// htab_size.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_size function
// for getting count of entries in hashtable

#include "htab_private.h"

size_t htab_size(const htab_t * t){
    return t->size;
}
