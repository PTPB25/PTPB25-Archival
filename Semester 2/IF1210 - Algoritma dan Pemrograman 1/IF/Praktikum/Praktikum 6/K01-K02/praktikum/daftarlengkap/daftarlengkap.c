
#include <stdio.h>
#include "liststatik.h"


int main(){
    int n, m, i, j;
    ListStatik a, b, result;

    CreateListStatik(&a);
    CreateListStatik(&b);
    CreateListStatik(&result);

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &ELMT(a, i));
    }

    scanf("%d", &m);
    for(i = 0; i < m; i++){
        scanf("%d", &ELMT(b, i));
    }

    i = 0;
    j = 0;
    while(i < n || j < m){
        if(i >= n){
            while(j < m){
                insertLast(&result, ELMT(b, j));
                j++;
            }
        }
        else if(j >= m){
            while(i < n){
                insertLast(&result, ELMT(a, i));
                i++;
            }
        }
        else{
            if(ELMT(a, i) < ELMT(b, j)){
                insertLast(&result, ELMT(a, i));
                i++;
            }
            else{
                insertLast(&result, ELMT(b, j));
                j++;
            }
        }
    }

    printList(result);
    printf("\n");

    return 0;
}