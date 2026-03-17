#include <stdio.h>
#include <stdlib.h>

/* No restriction imposed about the usage of ADT */

int main(){

    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", arr + i);
    }   

    /* Just bruteforce the max for this one*/

    int ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l; r < n; r++){
            int max = -1;
            for(int i = l; i <= r; i++){
                if(max < arr[i]){
                    max = arr[i];
                }
            }
            ans += max;
        }
    }

    printf("%d\n", ans);
    return 0;
}