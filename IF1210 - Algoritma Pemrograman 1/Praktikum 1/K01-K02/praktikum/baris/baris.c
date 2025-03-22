#include <stdio.h>


int main(){
    int n, sumOfIndex, i, j, k, number;
    int arr[100][100];

    scanf("%d", &n);

    sumOfIndex = 0;
    number = 1;

    for(k = 1; k <= n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i+j == sumOfIndex){
                    arr[i][j] = number;
                    number++;
                }
            }
        }
        sumOfIndex++;
    }   

    for(k = n-1; k >= 1; k--){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i+j == sumOfIndex){
                    arr[i][j] = number;
                    number++;
                }
            }
        }
        sumOfIndex++;
    }  

    for(i = 0; i<n; i++){
        for(j =0; j<n; j++){
            if(j==n-1){
                printf("%d\n", arr[i][j]);
            }
            else{
                printf("%d ", arr[i][j]);
            }
        }
    }

    return 0;
}