#include <stdio.h>

int checkPrime(int x){
    if (x<=1) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0) return 0;
    else{
        for (int i = 3; i * i <= x; i+=2){
            if (x%i==0) return 0;
        }
        return 1;
    }
}

int main(){
    int A,B;
    int count = 0;
    scanf("%d %d",&A, &B);

    for(int i = A; i<=B; i++){
        if(checkPrime(i)) count++;
    }

    printf("%d\n", count);
}