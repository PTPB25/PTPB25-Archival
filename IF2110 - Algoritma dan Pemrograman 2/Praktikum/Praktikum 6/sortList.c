#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Fungsi yang melakukan pengurutan dengan urutan menaik jika asc = true
 * dan menurun jika asc = false
 * 
 * I.S. List l terdefinisi dan berisi setidaknya 1 elemen
 * F.S. List l terurut secara urutan tertentu
 * 
 * Contoh: 
 * - Untuk l = [1, 5, 2, 3, 3], maka setelah sort(&l, true), l menjadi [1, 2, 3, 3, 5]
 * 
 * Banyak elemen yang diujikan memiliki batasan (1 <= N <= 1000)
 */

void sort(List *l, boolean asc){
    /* KAMUS LOKAL
     * 
     * left     : Address {pointer ke node sebelah kiri saat traversal, yaitu tempat dimana node dengan nilai terkecil/terbesar di sebelah kanan akan di-swap}
     * right    : Address {pointer ke node sebelah kanan, digunakan untuk mencari node dengan nilai terkecil/terbesar di sebelah kanan node 'left' }
     * toSwap   : Address {pointer ke node yang akan di-swap nilainya dengan node 'left' }
     * temp     : int {nilai elemen yang digunakan sementara untuk perbandingan nilai, dan nilai sementara untuk operasi swap }
     */
    

    /* ALGORITMA */
    Address left = FIRST(*l);
    Address right, toSwap;
    int temp;
    while(left != NULL){ /* Selection sort */
        temp = INFO(left);
        toSwap = left;

        right = NEXT(left);
        while(right != NULL){
            if((asc && INFO(right) < temp) || (!asc && INFO(right) > temp)){
                temp = INFO(right);
                toSwap = right;
            }
            right = NEXT(right);
        }

        temp = INFO(left);
        INFO(left) = INFO(toSwap);
        INFO(toSwap) = temp;
        left = NEXT(left);
    }
}