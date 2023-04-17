#include "htab_private.h"
#include <stdio.h>

void htab_statistics(const htab_t * t){
    if(t == NULL || t->arr_ptr == NULL || t->size == 0){
        fprintf(stderr, "Nothing to make statistics from in this hash table\n");
        return;
    }
    
    size_t* list_length = malloc(t->arr_size * sizeof(size_t));
    if(list_length == NULL){
        fprintf(stderr, "Allocation error\n");
    }
    for(size_t i = 0; i < t->arr_size; i++){
        size_t temp = 0;
        if(t->arr_ptr[i] != NULL){
            for(htab_item_t* item = t->arr_ptr[i]; item != NULL; item = item->next){
                temp++;
            }
        }
        list_length[i] = temp;
    }

    size_t min = list_length[0], max = list_length[0], avg = list_length[0];

    for(size_t i = 1; i < t->arr_size; i++){
        avg += list_length[i];
        if(list_length[i] > max){
            max = list_length[i];
        }
        if(list_length[i] < min){
            min = list_length[i];
        }
    }

    avg /= t->arr_size;

    fprintf(stderr, "Maximal lenght of list is %lu\n", max);
    fprintf(stderr, "Minimal lenght of list is %lu\n", min);
    fprintf(stderr, "Average lenght of list is %lu\n", avg);

    free(list_length);
}