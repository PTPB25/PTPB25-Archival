
#include "listkontigu.h"
#include <stdio.h>

int main(){
    ListKontigu list;
    CreateList(&list);
    readList(&list);
    
    int n = listLength(list);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n;k++){
                int a = ELMT(list, i);
                int b = ELMT(list, j);
                int c = ELMT(list, k);
                if(a < c && c < b){
                    printf("Nyalakan\n");
                    return 0;
                }
            }
        }
    }
    printf("Santai\n");
    return 0;
}