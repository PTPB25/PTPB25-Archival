#include <stdio.h>


long long totalVirus(long long N, long long X, long long T){
    long long prev, curr, dummy;
    int i;
    prev = 0;
    curr = N;
    for(i = 1; i <= T ;i++){
        dummy = curr;
        curr = curr + (curr - prev) * X;
        prev = dummy;
    }
    return curr;
}

int main(){
    long long N, T, X;
    scanf("%lld", &N);
    scanf("%lld", &T);
    scanf("%lld", &X);
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%lld\n", totalVirus(N, X, T), T);
    return 0;
}
