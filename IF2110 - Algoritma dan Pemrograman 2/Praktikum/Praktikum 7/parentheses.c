
#include <stdio.h>

int countPar(int left, int right){
    if(right < left) return 0;
    if(left == 0) return 1;
    return countPar(left - 1, right) + countPar(left, right - 1);
}

int main(void){
    int n;
    scanf("%d", &n);
    if(n == 0) printf("0\n");
    else printf("%d\n", countPar(n, n));
    return 0;
}