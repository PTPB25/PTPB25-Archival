
#include "../listlinier.h"
#include <stdio.h>

void removeAll(List *l, ElType val){

    List result;
    CreateList(&result);

    Address curr = FIRST(*l);
    ElType x;

    while(curr){
        if(INFO(curr) != val){
            insertLast(&result, INFO(curr));
        }
        curr = NEXT(curr);
    }

    *l = result;
    displayList(*l);
    printf("\n");
}
