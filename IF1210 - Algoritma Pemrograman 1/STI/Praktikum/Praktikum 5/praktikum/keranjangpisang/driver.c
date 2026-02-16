#include <stdio.h>
#include "keranjangpisang.h"

int main(){
    //Mock data
    KeranjangPisang Bananas;
    readKeranjang(&Bananas);
    printKeranjang(Bananas);
    printf("Length: %d\n", lengthKeranjang(Bananas));
    
    printf("\nADD function\n");
    ElType val1, val2, val3;
    IdxType id;
    printf("(id meant at what index) First, insertat, lastinsert, insertat id: ");
    scanf("%d %d %d %d", &val1, &val2, &val3, &id);
    insertFirst(&Bananas, val1);
    printKeranjang(Bananas);
    insertAt(&Bananas, val2, id);
    printKeranjang(Bananas);
    insertLast(&Bananas,val3);
    printKeranjang(Bananas);
    printf("Length: %d\n", lengthKeranjang(Bananas));

    printf("\nDELETE FUNCTION\n");
    ElType del1, del2, del3;
    printf("Deleting previously added nums\n");
    deleteAt(&Bananas, &del2, id);
    printKeranjang(Bananas);
    deleteFirst(&Bananas,&del1);
    printKeranjang(Bananas);
    deleteLast(&Bananas, &del3);
    printf("Deleted elements are: %d %d %d\n", del1, del2, del3);
    printKeranjang(Bananas);
    printf("Length: %d\n", lengthKeranjang(Bananas));

}