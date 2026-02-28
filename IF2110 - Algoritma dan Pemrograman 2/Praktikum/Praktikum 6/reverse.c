/* File: reverse.c */
/* Implementasi fungsi untuk membalik linked list */

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk membalik linked list secara in-place
 * I.S. l terdefinisi, mungkin kosong
 * F.S. Elemen-elemen dalam list l dibalik urutannya
 *
 * Contoh:
 * Jika l adalah [1,2,3,4,5], maka setelah reverseList(&l), l menjadi [5,4,3,2,1]
 * Jika l adalah [], maka setelah reverseList(&l), l tetap []
 * Jika l adalah [1], maka setelah reverseList(&l), l tetap [1]
 * 
 * Hint: Gunakan 3 pointer (prev, current, next) untuk membalik arah pointer
 *       Jangan lupa update FIRST(l) di akhir!
 */
void reverseList(List *l) {
    /* KAMUS LOKAL
     * 
     * prev : Address {pointer ke alamat node sebelum node utama yang ditunjuk sekarang dalam traversal}
     * curr : Address {pointer ke alamat node utama yang ditunjuk sekarang dalam traversal}
     * next : Address {pointer ke alamat node setelah node utama, sebelum node utama dibalik}
     */

    /* ALGORITMA */
    Address curr = FIRST(*l), prev = NULL, next;
    while(curr != NULL){
        next = NEXT(curr);
        NEXT(curr) = prev;
        prev = curr;
        curr = next;
    }
    FIRST(*l) = prev;
}
