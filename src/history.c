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

    //this is all the creation of the node itself
    Item *newItem= (Item*)malloc(sizeof(Item));//creates a node 
    newItem->id=0;
    int charCount = 0;
    for(int i = 0; str[i] != 0; i++){ //to count the number of characters in the string 
        charCount++;
    }
    char *data= (char*)malloc(charCount*sizeof(char));//assignes a memory allocation
    *data= copy_str(*str,charCount);//copies the strings data for transplant
    newItem->str=data;//makes the node's str value match the input string
    newItem->next=NULL;
    //next we need to check if the linked list has a node in it or if it is empty

    if(list->root == NULL){ //this should make it so that the new node becomes the root
        list->root=newItem;
    }

    //next i need to traverse to the end of a linked list to add a new item if the root is not empty
    if(list->root!=NULL){
        int traverse=0;
        Item *current=list->root;//creates a traveresal item
        while(current->next!=NULL){//goes to the end of the linked list
            traverse+=1;
            current=current->next;
        }
        newItem->id=traverse;
        current->next=newItem;//should make the last item of the linked list the newly added item
    }
}

char *get_history(List *list, int id){
    if(list->root==NULL){//error throw
        fputs('Error: no history found', stdout);
        return;
    }

    Item *current=list->root;
    while (current->id!=id){//traverses list
        current=current->next;
    }
    return current->str;

}

void print_history(List *list){
    if(list->root==NULL){//error throw
        fputs('Error: no history found', stdout);
        return;
    }

    Item *current=list->root;
    while(current->next!=NULL){
        printf("id: %n, entry: %s",current->id,current->str);
        current=current->next;
    }

}