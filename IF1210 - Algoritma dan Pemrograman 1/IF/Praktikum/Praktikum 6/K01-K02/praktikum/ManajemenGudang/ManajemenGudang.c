
#include <stdio.h>
#include "liststatik.h"

int main(){
    const char *pesan = "Aw, gabisa ngelakuin aksi itu";
    int type, idx, val;
    ListStatik arr;

    CreateListStatik(&arr);

    scanf("%d", &type);
    while(type != -1){
        if(type){
            scanf("%d %d", &val, &idx);
            if(isFull(arr) || idx > listLength(arr)){
                printf("%s\n", pesan);
            }
            else{
                insertAt(&arr, val, idx);
            }
        }
        else{
            scanf("%d", &idx);
            if(isEmpty(arr) || !isIdxEff(arr, idx)){
                printf("%s\n", pesan);
            }
            else{
                deleteAt(&arr, &val, idx);
            }
        }
        printList(arr); 
        printf("\n");

        scanf("%d", &type);
    }

    return 0;
}