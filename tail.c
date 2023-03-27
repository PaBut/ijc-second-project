#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 4095

typedef struct{
    char** array;
    int start_index;
    int end_index;
    int length;
}circular_buffer;

circular_buffer* cb_create(int n){
    circular_buffer* cb = malloc(sieof(circular_buffer));
    if(cb == NULL){
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }
    cb->length = n;
    cb->start_index = 0;
    cb->end_index = 0;
    if((cb->array = malloc(n * sizeof(char*))) == NULL){
        fprintf(stderr, "Failed to allocate memory\n");
        free(cb);
        return NULL;
    }
    for(int i = 0; i < n; i++){
        if((cb->array[i] = malloc(MAX_LINE_LENGTH * sizeof(char))) == NULL){
            free(cb->array);
            free(cb);
            fprintf(stderr, "Failed to allocate memory\n");
            return NULL;
        }
    }
    return cb;
}


void cb_put(circular_buffer* cb, char* line){
    strcpy(cb->array[cb->end_index], line);
    cb->end_index = ++cb->end_index % cb->length;
}


char* cb_get(circular_buffer* cb){
    char* line = cb->array[cb->start_index++];
    cb->start_index %= cb->length;
    return line;
}

void cb_free(circular_buffer* cb){
    for(int i = 0; i < cb->length; i++){
        free(cb->array[i]);
    }
    free(cb->array);
    free(cb);
}

int main(int argc, char** argv){
    int lines = 10;
    int offset = 1;
    FILE* input = stdin;
    //Getting final count of lines if set -n
    if(argc > 1){
        if(strcmp(argv[offset], "-n")){
            //Checking if -n has an argument
            if(argc < 3){
                fprintf(stderr, "The value for -n must be set");
                return EXIT_FAILURE;
            }
            lines = atoi(argv[offset + 1]);
            offset += 2; 
        }    
        //If source file given, then changing stdin to file
        if(offset + 1 < argc){
            input = fopen(argv[offset], "r");
        }   
    }
    

    


    if(input != stdin){
        fclose(input);
    }
    return EXIT_SUCCESS;
}