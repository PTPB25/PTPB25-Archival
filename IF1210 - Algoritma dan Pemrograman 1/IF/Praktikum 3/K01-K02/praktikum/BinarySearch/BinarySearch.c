#include <stdio.h>

int BinarySearch(int arr[], int left, int right, int target){
    int mid, ans;

    ans = -1;
    while(left <= right){
        mid = (left + right) >> 1;
        if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
            ans = mid;
        }
    }

    return (ans != -1 && arr[ans] == target ? ans : -1);
}


int main(){
    int n, q, target, i;
    scanf("%d", &n);

    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }
    
    scanf("%d", &q);
    printf("[");
    while(q--){
        scanf("%d", &target);
        if(q){
            printf("%d, ", BinarySearch(arr, 0, n-1, target));
        }
        else{
            printf("%d]\n", BinarySearch(arr, 0, n-1, target));
        }
    }
    return 0;
}