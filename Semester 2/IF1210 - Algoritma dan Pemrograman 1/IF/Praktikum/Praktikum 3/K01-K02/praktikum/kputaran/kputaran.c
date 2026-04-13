#include <stdio.h>


void rotateRightOnce(int arr[], int n){
    int temp, i;
    temp = arr[n-1];
    for(i=n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}


int main(){

    int n, k, i;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    k %= n;
    for(i=0; i<k; i++){
        rotateRightOnce(arr, n);
    }

    for(i=0; i<n; i++){
        if(i==n-1){
            printf("%d\n", *(arr+i));
        }
        else{
            printf("%d ", *(arr+i));
        }
    }
    return 0;
}