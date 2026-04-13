#include "../matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Matrix matrix;
    int n, m, k, x;
    scanf("%d %d %d %d", &n, &m, &k, &x);
    createMatrix(n, m, &matrix);
    readMatrix(&matrix, n, m);

    int ans = 0;
    for(int i = 0; i + k - 1 < n; i++){
        for(int j = 0; j + k - 1 < m; j++){
            int sum = 0;
            for(int a = i; a <= i + k - 1; a++){
                for(int b = j; b <= j + k - 1; b++){
                    sum += ELMT(matrix, a, b);
                }
            }
            if(sum <= x){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}