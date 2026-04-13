
#include <stdio.h>

int countTile(int n){
    if(n == 1 || n == 2) return n;
    return countTile(n - 1) + countTile(n - 2);
}

int main(void){
    int n;
    scanf("%d", &n);
    printf("%d\n", countTile(n));
    return 0;
}