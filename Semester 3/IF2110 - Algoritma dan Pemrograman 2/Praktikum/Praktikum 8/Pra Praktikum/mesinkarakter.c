#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

void START(){
    currentChar = getchar();
    if(currentChar == MARK){
        EOP = true;
    }
    else{
        EOP = false;
    }
}

void ADV(){
    currentChar = getchar();
    if(currentChar == MARK){
        EOP = true;
    }
}