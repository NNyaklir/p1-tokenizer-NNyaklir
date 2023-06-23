#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 2048

int main(){
    puts("Initializing Tokenizer\n");

    while(1){//infinite loop for ui to run

        fputs("Enter expression to tokenize. Type \"exit\" to exit\n",stdout); //stdout shows that the output is going to the shell
        fflush(stdout);//fflush immediately flushes the contents of an output stream
        char input[MAX]; //input buffer
        scanf("%s",input);
        printf("Recorded string: %s\n",input);


        char exitCondition[]= "exit";

        if(strcmp(input,exitCondition)==0){
            goto done;      //end program
        }


    }

    done:       //exits program
        return 0;

}