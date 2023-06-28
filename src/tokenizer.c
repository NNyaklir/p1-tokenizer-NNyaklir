#include "stdlib.h"
#include "tokenizer.h"
#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
    if(c==' ' || c=='\t' || c=='\n' || c==EOF){
        return 1;
    }
    else{
        return 0;
    }
}

int non_space_char(char c){
    if(c==' ' || c=='\t' || c=='\n' || c==EOF){
        return 0;
    }
    else{
        return 1;
    }
}

char *token_start(char *str){
    if( str==NULL || *str=='\0'){ //this checks if the string is empty or the pointer points to nothing
        return 0;                  // since the str or *str is empty this fufills the return zero condition.
    }
    int charCheck = space_char(*str);
    while(charCheck==1){// this will move foward until whitespace or end of string
        if(charCheck==0){ //checks if the pointer has a nontab or whitespace entry
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
            char *updateStart= *start + *end;
            start= token_start(updateStart);
            end = token_terminator(updateStart);
        }
    }
    return count;
}

char *copy_str(char *inStr,short len){
    int numTokens=count_tokens(inStr);
    char *outStr = (char*)malloc((len+numTokens)*sizeof(char)); //dynamically allocated array
    char endToken = token_terminator(token_start(inStr));
    int counter=0;
    
    for (int i = 0; i < len && inStr[i] != 0; i++){//iterates through string to be coppied
        if (!space_char(inStr[i])){//this loop copies the string if there is a non space char in [i]
            outStr[counter] = inStr[i];
            counter++;
        }
        else if(&inStr[i] == endToken){//this updates the end token if it reaches the end
            outStr[counter] = 0;
            counter++;
            endToken = token_terminator(token_start(endToken));
         }
        else if(inStr[i] == 0){//exit condition
            break;
        }
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