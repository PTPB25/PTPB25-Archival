#include <stdio.h>
#include <stdlib.h>
#include "tester.h"


typedef struct s_nimon{
    int id;
    int status;
    int value;
} Nimon;

/* return 1 jika prioritas a lebih besar daripada prioritas b, else return 0 */
int compareNimon(Nimon a, Nimon b){
    if(a.status == b.status){
        if(a.value == b.value){
            return a.id > b.id;
        }   
        else{
            return a.value > b.value;
        }
    }
    else{
        if(a.status == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
}

void sort(Nimon *arr, int n){
    int i, j;
    Nimon temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(compareNimon(arr[j], arr[j+1])){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int main(){
    init();
    FILE *f = fopen("input.txt", "r");
    FILE *q = fopen("query.txt", "r");
    
    Nimon arr[2000];

    int a, b, c, i = 0;
    fscanf(f, "%d %d %d", &a, &b, &c);
    while(a != -1 || b != 0 || c!= 0){
        arr[i].id = a;
        arr[i].status = b;
        arr[i].value = c;
        fscanf(f, "%d %d %d", &a, &b, &c);
        i++;
    }
    
    sort(arr, i);

    int query, k;
    fscanf(q, "%d", &query);
    while(query--){
        fscanf(q, "%d", &k);
        printf("%d %d\n", arr[k-1].id, arr[k-1].value);
    }
    return 0;
}
