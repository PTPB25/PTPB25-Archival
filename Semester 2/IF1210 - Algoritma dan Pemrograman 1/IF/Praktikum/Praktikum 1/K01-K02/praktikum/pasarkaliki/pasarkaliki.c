#include <stdio.h>

int main(){
    int n, i, j;
    long long result;
    scanf("%d", &n);
    
    for(i = 0;i < n; i++){

        for(j = 0; j < n-i-1 ; j++){
            printf(" ");
        }

        for(j = 0; j <= i; j++){

            if(j == 0){
                result = 1ll;
            }
            else{
                result *= i-j+1;
                result /= j;
            }

            if(j == i){
                printf("%lld\n", result);
            }
            else{
                printf("%lld ", result);
            }

        }

    }

    return 0;
}