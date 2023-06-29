#include <stdio.h>
#include <stdlib.h>
#include "stdio.h"
#include "history.h"
#include "stdlib.h"

List* init_history(){
    List *historyList = malloc(sizeof(List)); //in theory it should dynamically allocate memory for a linked list via pointer
    historyList->root=0; //gives a root to the list
    return historyList; //returns the newly allocated linked list
}

void add_history(List *list, char *str){ //char  *str is a pointer to a string
    Item *newItem= (Item*)malloc(sizeof(Item));
    newItem->id=0;

    int charCount = 0;
    for(int i = 0; str[i] != 0; i++){ //to count the number of characters in the string 
        int charCheck= non_space_char(str[i]);
        if(charCheck==0){
            charCount++;
        }
    }
    char *data= (char*)malloc(charCount*sizeof(char));
    *data= copy_str(*str,charCount);
    newItem->str=data;
    

}