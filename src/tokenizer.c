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