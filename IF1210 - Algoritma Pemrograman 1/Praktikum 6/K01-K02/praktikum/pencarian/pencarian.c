

#include <stdio.h>
#include <string.h>
#include "listdin.h"

int main(){
    int n, i, j;
    float avg, min;
    char ans[25];
    const char *nimons[] = {"Kebin", "Stewart", "Pop", "Luiy", "Toto"};
    ListDin first, last;

    scanf("%d", &n);
    CreateListDin(&first, 5);
    CreateListDin(&last, 5);

    for(j = 0; j < 5; j++){
        scanf("%d", BUFFER(first) + j);
    }

    for(i = 1; i < n; i++){
        for(j = 0; j < 5; j++){
            scanf("%d", BUFFER(last) + j);
        }
    }

    min = 1e15;
    for(j = 0; j < 5; j++){
        avg = ((float) BUFFER(last)[j] - (float) BUFFER(first)[j]) / n;
        if(avg < min){
            min = avg;
            strcpy(ans, nimons[j]);
        }
    }
    printf("%s\n", ans);
    return 0;
}