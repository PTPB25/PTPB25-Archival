#include <stdio.h>
#include "graph.h"

int main(void){

    int n, m;
    scanf("%d %d", &n, &m);

    int id[n], in[n];
    for(int i = 0; i < n; i++){
        scanf("%d", id + i);
        in[i] = 0;
    }

    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        for(int j = 0; j < n; j++){
            if(id[j] == b){
                in[j]++;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d\n", id[i], in[i]);
    }

    return 0;
}