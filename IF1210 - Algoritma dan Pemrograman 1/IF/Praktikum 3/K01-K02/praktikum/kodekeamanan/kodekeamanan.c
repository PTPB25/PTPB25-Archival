#include <stdio.h>

int main(){

    int n, target, i, j, l, r;
    scanf("%d", &n);

    int arr[n];
    for(i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    scanf("%d", &target);

    l = -1;
    r = -1;
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(l==-1 && r==-1 && arr[i] + arr[j] == target){
                l = i;
                r = j;
            }
        }
    }
    
    printf("[%d, %d]\n", l, r);
    
    return 0;
}