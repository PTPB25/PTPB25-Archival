
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


List removeDuplicates(List l) {
    if(isEmpty(l)){ 
        return NIL;
    } 
    else{ 
        if(search(tail(l), head(l))){
            deleteX(&l, head(l));
            return removeDuplicates(l);
        }
        else return konso(head(l), removeDuplicates(tail(l)));
    }
}