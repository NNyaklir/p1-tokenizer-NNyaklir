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

