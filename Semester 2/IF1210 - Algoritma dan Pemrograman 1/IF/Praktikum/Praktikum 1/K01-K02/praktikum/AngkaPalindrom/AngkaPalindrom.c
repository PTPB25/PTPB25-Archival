#include <stdio.h>

int main(){
    int n, temp, numOfDigits, i, j, ans, divisor_r, divisor_l, l, r;
    scanf("%d", &n);
    temp = n;
    numOfDigits = 0;

    while(temp > 0){
        temp /= 10;
        numOfDigits++;
    }

    ans = 1;
    for(i = 0; i < (numOfDigits+1)/2; i++){
        divisor_l = 1;
        divisor_r = 1;
        for(j=0; j < i; j++){
            divisor_r *= 10;
        }
        for(j=0; j < numOfDigits-i-1; j++){
            divisor_l *= 10;
        }
        r = (n / divisor_r) % 10;
        l = (n / divisor_l) % 10;
        if(l != r){
            ans = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}