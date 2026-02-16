
#include "listkontigu.h"
#include <stdio.h>


int main(){
    ListKontigu list, copy;
    CreateList(&list);
    CreateList(&copy);
    readList(&list);
    int n = listLength(list);

    int valid = 1;
    for(int i=0; i < n-1; i++){
        if(ELMT(list, i) > ELMT(list, i+1)){
            valid = 0;
        }
    }
    if(valid){
        printf("YA\n");
        return 0;
    }
   
    for(int l = 0; l < n; l++){
        for(int r = l+1; r < n; r++){
            valid = 1;
            copyList(list, &copy);
            int len = r-l+1;
            int i = l, j = r;
            while(i <= j){
                int temp = ELMT(copy, i);
                ELMT(copy, i) = ELMT(copy, j);
                ELMT(copy, j) = temp;
                i++; j--;
            }

            for(int i=0; i < n-1; i++){
                if(ELMT(copy, i) > ELMT(copy, i+1)){
                    valid = 0;
                }
            }

            if(valid){
                printf("YA\n");
                printf("%d %d\n", l, r);
                return 0;
            }
        }
    }
    printf("TIDAK\n");
}