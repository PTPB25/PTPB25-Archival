#include "time.h"
#include <stdio.h>

int main(){
    int n, i;
    scanf("%d", &n);

    TIME awal, akhir;
    awal = (TIME){23, 59, 59};
    akhir = (TIME){0, 0, 0};

    for(i=1; i <= n; i++){
        printf("[%d]\n", i);

        TIME T1, T2;
        BacaTIME(&T1);
        BacaTIME(&T2);   

        if(!TGT(T2, T1)){
            printf("%ld\n", Durasi(T2, T1));
        }
        else{
            printf("%ld\n", Durasi(T1, T2));
        }

        if(TGT(awal, T1))awal = T1;
        if(TGT(awal, T2))awal = T2;
        if(TLT(akhir, T1))akhir = T1;
        if(TLT(akhir, T2))akhir = T2;
    }

    TulisTIME(awal); printf("\n");
    TulisTIME(akhir); printf("\n");
}