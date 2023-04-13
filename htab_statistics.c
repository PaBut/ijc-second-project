#include "htab_private.h"
#include <stdio.h>

void htab_statistics(const htab_t * t){
    if(t->arr_ptr == NULL || t == NULL){
        fprintf(stderr, "Nothing to make statistics from in this hash table\n");
        return;
    }
    size_t list_length[] = malloc(t->size * sizeof(size_t));
    if(list_length == NULL){
        fprintf(stderr, "Allocation error\n");
    }
    for(size_t i = 0; i < t->size; i++){
        size_t temp = 0;
        if(t->arr_ptr[i] != NULL){
            for(htab_item_t* item = t->arr_ptr[i]; item->next != NULL; item = item->next){
                temp++;
            }
        }
        list_length[i] = temp;
    }

    size_t min = 0, max = 0, avg = 0;

    for(size_t i = 0; i < t->size; i++){
        avg += list_length[i];
        if(list_length[i] > max){
            max = list_length[i];
        }
        if(list_length[i] < min){
            min = list_length[i];
        }
    }

    avg /= t->size;

    fprintf(stderr, "Maximal lenght of list is %u\n", max);
    fprintf(stderr, "Minimal lenght of list is %u\n", min);
    fprintf(stderr, "Average lenght of list is %u\n", avg);

    free(list_length);
}