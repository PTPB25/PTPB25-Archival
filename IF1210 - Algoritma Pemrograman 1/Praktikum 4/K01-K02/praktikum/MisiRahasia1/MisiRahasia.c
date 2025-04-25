#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int main(){
    init();
    FILE *f = fopen("input.txt", "r");
    int a, b, c, totalMisi, misiBerhasil, nilai;
    totalMisi = misiBerhasil = nilai = 0;
    fscanf(f, "%d %d %d", &a, &b, &c);
    while(a != -1 || b != 0 || c!= 0){
        totalMisi++;
        if(b){
            misiBerhasil++;
            nilai += c;
        }
        fscanf(f, "%d %d %d", &a, &b, &c);
    }
    printf("Total Misi: %d\n", totalMisi);
    printf("Misi Berhasil: %d\n", misiBerhasil);
    printf("Total Nilai Misi: %d\n", nilai);
    return 0;
}
