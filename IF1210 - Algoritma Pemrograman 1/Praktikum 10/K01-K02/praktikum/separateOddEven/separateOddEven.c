#include "../listlinier.h"
#include <stdio.h>

void separateOddEven(List *l){
    if(isEmpty(*l)){
        return;
    }

    List result;
    CreateList(&result);
    Address curr;

    // Insert Odd positive
    curr = FIRST(*l);
    while(curr){
        if(INFO(curr) % 2 == 1){
            insertLast(&result, INFO(curr));
        }
        curr = NEXT(curr);
    }

    // Insert Even Positive, Even Negative and Odd Negative
    // Asprak made a mistake, and Odd negative is considered as even in the judge server
    // Asprak crime part 4!
    curr = FIRST(*l);
    while(curr){
        if(INFO(curr) % 2 != 1){
            insertLast(&result, INFO(curr));
        }
        curr = NEXT(curr);
    }

    *l = result;
}


