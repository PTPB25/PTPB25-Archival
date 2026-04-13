#include <stdio.h>


int main(){
    int N, prev, curr, i, dummy;
    scanf("%d", &N);
    if(N == 0){
        printf("1\n");
    }
    else if(N == 1){
        printf("1 1\n");
    }
    else{
        prev = 1;
        curr = 1;
        printf("1 1 ");
        for(i = 0; i<N-1 ; i++){
            dummy = curr;
            curr = curr+prev;
            prev = dummy;
            if(i == N-2){
                printf("%d\n", curr);
            }
            else{
                printf("%d ", curr);
            }
        }
    }
}