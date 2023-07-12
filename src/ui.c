#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 2048

int main(){
    puts("Initializing Tokenizer\n");

    List *tokenList=init_history();

    while(1){//infinite loop for ui to run

        loop:

        fputs("Enter expression to tokenize. Type \"exit\" to exit\n",stdout); //stdout shows that the output is going to the shell
        printf(">");
        fflush(stdout);//fflush immediately flushes the contents of an output stream
        char input[MAX]; //input buffer

        scanf("%s",input);

        printf("Recorded string: %s\n",input);


        char exitCondition[]= "exit";
        char historyCondition[]= "history";

        if(strcmp(input,historyCondition)==0){
            printf("intializing history");
            print_history(tokenList);
            goto loop;
        }

        /*else if(strcmp(input,exitCondition)==0){
            free_history(tokenList);
            goto done;      //end program
        }*/
        //else{
        //    add_history(tokenList,input);
        //    goto loop;
        //}


    }

    done:       //exits program
        printf("program killed");
        return 0;

}