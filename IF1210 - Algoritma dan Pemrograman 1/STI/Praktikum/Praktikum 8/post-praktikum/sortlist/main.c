#include <stdio.h>
#include "listlinier.h"

int main(){
    List l;
    CreateEmpty(&l);
    InsVFirst(&l, 5);
    InsVFirst(&l, 3);
    InsVFirst(&l, 10);
    InsVFirst(&l, 7);
    InsVFirst(&l, 25);
    InsVFirst(&l, 3);
    InsVFirst(&l, 48);

    SortListAsc(&l);
    PrintInfo(l);
}