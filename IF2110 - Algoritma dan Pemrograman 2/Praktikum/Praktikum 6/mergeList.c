#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Fungsi untuk menggabungkan nilai-nilai di antara dua node bernilai 0
 * menjadi satu node dengan nilai hasil penjumlahan, dan menghapus seluruh node 0.
 *
 * I.S.  l terdefinisi, berisi minimal tiga elemen, dengan ketentuan:
 *      - Elemen pertama dan terakhir bernilai 0
 *      - Tidak ada dua node 0 yang bersebelahan
 *
 * F.S.  Setiap rentang elemen di antara dua 0 dijumlahkan menjadi satu node baru,
 *       dan list hasil tidak mengandung nilai 0 sama sekali.
 *
 * Contoh:
 * Jika l = [0,3,1,0,4,5,2,0], maka setelah mergeList(&l), l menjadi [4,11]
 * Jika l = [0,1,0,3,0,2,2,0], maka setelah mergeList(&l), l menjadi [1,3,4]
 *
 * Hint:
 * - Gunakan variabel untuk menampung hasil penjumlahan sementara
 * - Jangan lupa update FIRST(l) di akhir!
 */
void mergeList(List *l) {
    /* KAMUS LOKAL
     *
     * left     : Address {pointer ke node sebelah kiri, yang akan menjadi tempat diletakkannya hasil sum saat ini}
     * right    : Address {pointer ke node sebelah kanan, yang akan mencari total sum saat ini}
     * temp     : Address {pointer ke node sementara yang akan digunakan jika dibutuhkan}
     * sum      : int {jumlah bilangan yang dijumlahkan saat ini}
     */


    /* ALGORITMA */
    Address left = FIRST(*l);
    Address right = left;
    Address temp;
    int sum;
    while(true){
        sum = 0;
        right = NEXT(right);
        while(INFO(right) != 0){
            sum += INFO(right);
            right = NEXT(right);
        }

        INFO(left) = sum;
        if(NEXT(right) == NULL){
            temp = left;
            left = NEXT(left);
            NEXT(temp) = NULL;
            break;
        }
        left = NEXT(left);
    }

    while(left != NULL){
        temp = NEXT(left);
        free(left);
        left = temp;
    }
}
