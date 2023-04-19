// tail.c
// IJC-DU2 solution, task 1), 19.04.2023
// Author: Pavlo Butenko, FIT
// Compiled with gcc 11.3
// prints the last specific count of lines(implicitly 10)
// from the file or stdin

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 4095

typedef struct{
    char** array;
    int start_index;
    int end_index;
    int length;
    bool is_full;
}circular_buffer;

circular_buffer* cb_create(int n){
    circular_buffer* cb = malloc(sizeof(circular_buffer));
    if(cb == NULL){
        fprintf(stderr, "Failed to allocate memory\n");
        return NULL;
    }
    cb->length = n;
    cb->start_index = 0;
    cb->end_index = 0;
    cb->is_full = false;
    if((cb->array = malloc(n * sizeof(char*))) == NULL){
        fprintf(stderr, "Failed to allocate memory\n");
        free(cb);
        return NULL;
    }
    for(int i = 0; i < n; i++){
        if((cb->array[i] = malloc((MAX_LINE_LENGTH + 1) * sizeof(char))) == NULL){
            free(cb->array);
            free(cb);
            fprintf(stderr, "Failed to allocate memory\n");
            return NULL;
        }
        cb->array[i][0] = 0;
    }
    return cb;
}

void cb_put(circular_buffer* cb, char* line){
    if(cb->is_full){
        cb->start_index++;
        cb->start_index %= cb->length;
    }
    strcpy(cb->array[cb->end_index++], line);
    if(cb->end_index >= cb->length){
        cb->end_index %= cb->length;
        cb->is_full = true;
    }
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

void close_file_stream(FILE* file){
    if(file != stdin){
        fclose(file);
    }
}

int main(int argc, char** argv){
    int lines = 10;
    int offset = 1;

    FILE* input = stdin;

    if(argc > 1){
        if(strcmp(argv[offset], "-n") == 0){
            if(argc < 3){
                fprintf(stderr, "The value for -n must be set\n");
                return EXIT_FAILURE;
            }
            lines = atoi(argv[offset + 1]);
            offset += 2; 
        }    
        if(offset < argc){
            input = fopen(argv[offset], "r");
            if(input == NULL){
                fprintf(stderr, "Cannot open %s\n", argv[offset]);
                return EXIT_FAILURE;
            }
        }
    }
    

    circular_buffer* cb = cb_create(lines);
    char* tmp_line = malloc((MAX_LINE_LENGTH + 1) * sizeof(char));
    if(tmp_line == NULL){
        cb_free(cb);
        close_file_stream(input);
        fprintf(stderr, "Failed to allocate memory\n");
        return EXIT_FAILURE;
    }

    bool warning = false;
    while(fgets(tmp_line, MAX_LINE_LENGTH + 1, input) != NULL){
        if(strchr(tmp_line, '\n') == NULL && strlen(tmp_line) == MAX_LINE_LENGTH){
            if(!warning){
                fprintf(stderr, "Warning: The line is too long. Must have at most 4095 symbols\n");
                warning = true;
            }
            int tmp_char;
            do{
                tmp_char = fgetc(input);
            }while(tmp_char != '\n' && tmp_char != EOF);
            if(tmp_char == '\n') tmp_line[MAX_LINE_LENGTH - 1] = tmp_char;
        }
        cb_put(cb, tmp_line);
    }

    for(int i = 0; i < lines; i++){
        char* line = cb_get(cb);
        if(line[0] == 0){
            close_file_stream(input);
            cb_free(cb);
            free(tmp_line);
            return EXIT_SUCCESS;
        }
        printf("%s", line);
    }

    free(tmp_line);
    close_file_stream(input);
    cb_free(cb);
    return EXIT_SUCCESS;
}