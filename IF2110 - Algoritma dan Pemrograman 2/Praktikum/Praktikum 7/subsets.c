#include <stdio.h>

void getSubsetWithSize(int idx, int n, int size, int *temp, int *arr, int target){

    if(idx == n){
        if(size == target){
            printf("[");
            for(int i = 0; i < size; i++){
                if(i) printf(",%d", temp[i]);
                else printf("%d", temp[i]);
            }
            printf("]\n");
        }
        return;
    }
    
    temp[size] = arr[idx];
    getSubsetWithSize(idx + 1, n, size + 1, temp, arr, target);
    getSubsetWithSize(idx + 1, n, size, temp, arr, target);
}

int main(void){
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }

    for(int targetSize = 0; targetSize <= n; targetSize++){
        getSubsetWithSize(0, n, 0, temp, arr, targetSize);
    }
}