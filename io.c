// io.c
// IJC-DU2 solution, task 2), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// Implementation of read_word function
// reads one word from file into the specified character array
// returns the length of the word or EOF

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "io.h"

int read_word(char *s, int max, FILE *f){
    if(s == NULL || f == NULL){
        fprintf(stderr, "Error here\n");
    }

    int c = 0, index = 0, length = 0;
    bool warning = false;

    while((c = fgetc(f)) != ' ' && c != '\n' && c != EOF){
        if(index <= max - 1){
            s[index++] = c;
        }
        else{
            if(!warning){
                fprintf(stderr, "Warning: The word length is longer than maximal allowed(%d)\n", max);
                warning = true;
            }
        }
        length++;
    }
    s[index] = '\0';
    if(c == EOF){
        return EOF;
    }
    return length;
}