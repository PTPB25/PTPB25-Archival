
#include <stdio.h>
#include "arrayutils.h"


/* Driver code for testing */

int main(){
    int n, i;
    scanf("%d", &n);
    int arr[n];

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, n);
    for(i=0; i<n; i++){
        if(i == n-1){
            printf("%d\n", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }

    reverseArray(arr, n);
    for(i=0; i<n; i++){
        if(i == n-1){
            printf("%d\n", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }

    printf("Modus: %d\n", findMode(arr, n));
    printf("Median: %d\n", findMedian(arr, n));


}