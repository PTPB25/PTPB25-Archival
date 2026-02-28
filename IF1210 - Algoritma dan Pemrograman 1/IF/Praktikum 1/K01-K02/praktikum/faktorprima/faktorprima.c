#include <stdio.h>

int main(){
    int n, i, cnt;
    scanf("%d", &n);
    for(i = 2; i*i <= n; i++){
        cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        
        if(cnt > 0){
            if(cnt > 1){
                printf("%d^%d", i, cnt);
            }
            else{
                printf("%d", i);
            }

            if(n == 1){
                printf("\n");
            }
            else{
                printf(" * ");
            }
        }
    }
    if(n > 1){
        printf("%d\n", n);
    }
    return 0;
}