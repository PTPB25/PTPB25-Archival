
#include "listkontigu.h"
#include <stdio.h>

int main(){
    ListKontigu list;
    CreateList(&list);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        int len = listLength(list), j = 0;
        while(j < len && ELMT(list, j) < val){
            j++;
        }
        insertAt(&list, val, j);
        printList(list);
        printf("\n");
    }
}