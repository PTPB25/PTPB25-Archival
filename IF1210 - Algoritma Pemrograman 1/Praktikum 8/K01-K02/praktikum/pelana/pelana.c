#include "../matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Matrix matrix;
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    createMatrix(rows, cols, &matrix);
    readMatrix(&matrix, rows, cols);

    int minRow[rows], maxCol[cols];
    for(int i = 0; i < rows; i++){
        int min = ELMT(matrix, i, 0);
        for(int j = 1; j < cols; j++){
            if(min > ELMT(matrix, i, j)){
                min = ELMT(matrix, i, j);
            }
        }
        minRow[i] = min;
    }

    for(int j = 0; j < cols; j++){
        int max = ELMT(matrix, j, 0);
        for(int i = 0; i < rows; i++){
            if(max < ELMT(matrix, i, j)){
                max = ELMT(matrix, i, j);
            }
        }
        maxCol[j] = max;
    }

    int cnt = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(maxCol[j] == minRow[i]){
                printf("(%d,%d,%d)\n", i, j, maxCol[j]);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}