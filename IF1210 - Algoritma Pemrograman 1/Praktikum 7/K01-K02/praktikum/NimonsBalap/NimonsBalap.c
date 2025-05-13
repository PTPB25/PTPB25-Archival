
#include "listkontigu.h"
#include <stdio.h>

int main(){
    ListKontigu list, output;
    CreateList(&list);
    CreateList(&output);
    readList(&list);
    
    int n = listLength(list);
    int k;
    scanf("%d", &k);

    for(int i = 0; i < n - k + 1; i++){
        int max = ELMT(list, i);
        for(int j = i; j < i+k; j++){
            if(max < ELMT(list, j)){
                max = ELMT(list, j);
            }
        }
        insertLast(&output, max);
    }
    printList(output);
    printf("\n");
}