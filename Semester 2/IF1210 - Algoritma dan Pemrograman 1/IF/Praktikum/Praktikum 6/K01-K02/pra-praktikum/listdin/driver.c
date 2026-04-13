
#include "listdin.h"
#include <stdio.h>

int main(){
    ListDin *l, *l2;
    CreateListDin(l, 5);
    readList(l);

    CreateListDin(l2, 5);
    readList(l2);
    

    return 0;
}