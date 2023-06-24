#include "stdlib.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int space_char(char c){

    switch (c){
        case ' ':
        return 1;
        break;

        case '\t':
        return 1;
        break;

        default:
        return 0;
    }
}

int non_space_char(char c){
    switch(c){
        case ' ':
        return 0;
        break;

        case '\t':
        return 0;
        break;

        default:
        return 1;
    }
}

char *token_start(char *str){
    if( str==NULL|| *str=='\0'){ //this checks if the string is empty or the pointer points to nothing
        return 0;                  // since the str or *str is empty this fufills the return zero condition.
    }

    while (*str != ' '){ //moves the pointer to the end of the word stopping at the whitespace
        *str++;
    }
    if(*str== '\0'){ //in the case of singular word arrays there will be no next word and thus will return 0
        return 0;
    }
    else{
        return *str; //if there is a next character this should the pointer to it.
    }
}

char *token_terminator(char *token){
    //im not sure what this is even supposed to do
}

int count_tokens(char *str){
    int count=0;
    if ( *str='\0'){ //if there is no pointer returns zero
        return 0;
    }
    else{ //this will count all the chars in a string and add it to count
        count++;
        while(*str!='\0'){
            count++;
            str++;
        }
    }
    return count;
}