#include "../matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Matrix matrix;
    int n;
    scanf("%d", &n);
    createMatrix(n, n, &matrix);
    readMatrix(&matrix, n, n);

    int found = 0;
    for(int k = 0; k < n; k++){
        unsigned char yes = 1;
        for(int i = 0; i < n; i++){
            if(k != i){
                if(ELMT(matrix, i, k) == 0){
                    yes = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            if(k != j){
                if(ELMT(matrix, k, j) == 1){
                    yes = 0;
                }
            }
        }

        if(yes){
            printf("%d\n", k);
            found = 1;
        }
    }
    if(!found){
        printf("%d\n", -1);
    }
}