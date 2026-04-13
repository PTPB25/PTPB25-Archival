#include <stdio.h>
#include "listlinier.h"

int main(){
    List l;
    CreateEmpty(&l);
    InsVFirst(&l, 5);
    InsVFirst(&l, 5);
    InsVFirst(&l, 10);
    InsVFirst(&l, 10);
    InsVFirst(&l, 10);
    InsVFirst(&l, 20);
    InsVFirst(&l, 20);

    RemoveDuplicate(&l);
    SortListAsc(&l);
    PrintInfo(l);
}