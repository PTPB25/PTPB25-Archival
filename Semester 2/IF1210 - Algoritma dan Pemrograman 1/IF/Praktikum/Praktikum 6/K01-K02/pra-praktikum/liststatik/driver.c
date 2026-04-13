
#include "liststatik.h"
#include <stdio.h>

int main(){
    ListStatik l;
    readList(&l);
    printList(l);
    printf("\n");

    sortList(&l, true);
    printList(l);
    printf("\n");

    sortList(&l, false);
    printList(l);
    printf("\n");
    return 0;
}