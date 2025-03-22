#include <stdio.h>

int main(){
    int n, i, j, a, b, ans;
    scanf("%d", &n);
    ans = 0;
    
    for(i = 1; i*i <= n; i++){
        if(n % i == 0){

            a  = n / i;
            b = i;

            for(j=1; j*j<=a; j++){
                if(j * j == a){
                    ans++;
                }
            }
            
            if(a != b){

                for(j=1; j*j<=b; j++){
                    if(j * j == b){
                        ans++;
                    }
                }

            }
        }
    }

    printf("%d\n", ans);
    return 0;
}