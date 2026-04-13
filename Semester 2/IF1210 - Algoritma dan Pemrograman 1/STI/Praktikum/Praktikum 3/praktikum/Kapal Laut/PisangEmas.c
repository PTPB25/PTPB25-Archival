#include <stdio.h>

int main(){
    int n, target, index;
    scanf("%d %d", &n, &target);
    int arr[n];

    for(int i = n-1; i>=0;i--){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i<n ; i++){
        if (arr[i] == target){
           if (i==0) {arr[i] = arr[i+1];}
           else if (i==n-1) {arr[i] = arr[i-1];}
           else {arr[i] = arr[i-1] + arr[i+1];}
           index = i;

           printf("%d", arr[i]);
           if (i<n-1){
                printf(" ");
            } 
           else {
            printf("\n");
            }
            break;
        }

        printf("%d", arr[i]);
        if (i<n-1) printf(" ");
        else printf("\n");
    }

    if (index<n){
        for(int i = n-1; i>index; i--){
            printf("%d", arr[i]);
            if (i>index+1) printf(" ");
            else printf("\n");
        }
    }
    
}