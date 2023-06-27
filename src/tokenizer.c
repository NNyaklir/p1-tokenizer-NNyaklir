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
    if( str==NULL || *str=='\0'){ //this checks if the string is empty or the pointer points to nothing
        return 0;                  // since the str or *str is empty this fufills the return zero condition.
    }

    while(*str!=' ' && *str!='\0'){// this will move foward until whitespace or end of string
        int charCheck= space_char( *str);
        if(charCheck==1){ //checks if the pointer has a nontab or whitespace entry
            return *str;
        }
        else{
            *str++; // increments the pointer by one if no character is found.
        }
    } 
}

char *token_terminator(char *token){
    if( token==NULL || *token=='\0'){ //this checks if the string is empty or the pointer points to nothing
        return 0;                  // since the str or *str is empty this fufills the return zero condition.
    }

    int charCheck = space_char(*token);
    while(charCheck!=1){ //while *token has a non tab non whitespace character, this will incriment
        *token++;
    }

    return *token; //in theory this should return a char that has whitespace at the end of a string/word

}

int count_tokens(char *str){ //This actually needs to count the amount of words in a string
    int count=0;
    char *start = token_start(str);
    char *end = token_terminator(str);
    if ( *str='\0'){ //if there is no pointer returns zero
        return 0;
    }
    else{ //this will count all the words in a string and add it to count
        while(*str!='\0'){
            count++;
            char *updateStart= *start+*end;
            *start= token_start(updateStart);
            *end = token_terminator(updateStart);
        }
    }
    return count;
}

char *copy_str(char *inStr,short len){
    int length = count_tokens(*inStr);
    char outStr[length];
    char *ptr=outStr; //allocating pointer to first pointer in the string
    
    int i=0;
    while (i=0,i<len,i++){
        *ptr=inStr[i]; // if I am correct this should copy the value from *inStr to *ptr
        *ptr++;
    }
    return outStr; //returns copied string
}

char **tokenize(char *str){
    int length_str= count_tokens(*str);
    char *tokens[10]; //an array of pointers to reduce wasted memory
    //I need a loop that will deconstuct the string into only words
    while(str != '\0'){ //keeps loop running until the end of the string
        char *start= token_start(*str);
        char *end= token_terminator(*str);

    }

}