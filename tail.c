#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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