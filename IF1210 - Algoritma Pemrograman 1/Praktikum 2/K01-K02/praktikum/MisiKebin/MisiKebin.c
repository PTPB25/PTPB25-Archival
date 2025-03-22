#include <stdio.h>


int isPrime(int n){
    int i;
    if(n==1 || n==0)return 0;
    for(i=2; i*i <=n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}

void countPrime(int A, int B, int *total){
    int i;
    *total = 0;
    for(i=A; i<=B; i++){
        if(isPrime(i)){
            (*total)++;
        }
    }
}

int main()
{
    int A, B, total;

    scanf("%d %d", &A, &B);

    countPrime(A, B, &total);

    printf("%d\n", total);

    return 0;
}