// htab_hash_function.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of htab_hash_function function
// hash function

#include <stdint.h>
#include "htab.h"

size_t htab_hash_function(const char *str) {
    uint32_t h=0;     
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}
