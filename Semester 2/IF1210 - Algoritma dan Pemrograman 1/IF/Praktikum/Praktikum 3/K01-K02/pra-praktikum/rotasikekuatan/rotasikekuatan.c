#include <stdio.h>

void rotateRight(int *arr, int n){
    int i, temp;

    temp = arr[n-1];
    for(i=n-1; i>0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main(){
    const int NMAX = 10000;
    int n, m, i, j, k;
    scanf("%d", &n);
    scanf("%d", &m);
    int arr[NMAX], rotation[NMAX]; 

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(i=0; i<m; i++){
        scanf("%d", &rotation[i]);
    }

    for(j=0; j<m; j++){
        
        k = rotation[j] % n; /* Math hacks, rotasi n kali sama aja dengan rotasi 0 kali */

        /* rotasi */
        for(i=0; i<k; i++){
            rotateRight(arr, n);
        }

        /* cetak */
        printf("[");
        for(i=0; i<n; i++){
            if(i == n-1){
                printf("%d]\n", arr[i]);
            }
            else{
                printf("%d, ", arr[i]);
            }
        }

        /* kembalikan seperti semula */
        for(i=0; i<(n-k);i++){
            rotateRight(arr, n);
        }
    }   
    
    return 0;
}