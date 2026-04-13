/* MODUL KERANJANG PISANG - LIST STATIK TANPA SORTING/SEARCHING/ARITMATIKA */
/* Berisi definisi dan semua primitif pemrosesan list statik integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */

/*  Kamus Umum */
#include <stdio.h>
#include "Boolean.h"
#include "keranjangpisang.h"

/* Definisi elemen dan koleksi objek */
// typedef int ElType;
// typedef int IdxType;

// typedef struct
// {
//     ElType contents[CAPACITY];
// } KeranjangPisang;

// #define ELMT(l, i) (l).contents[(i)]

/* Indeks yang digunakan [0..CAPACITY-1] */

/* ********** KONSTRUKTOR ********** */
void CreateKeranjang(KeranjangPisang *k){
    for(int i = 0; i<CAPACITY; i++){
        k->contents[i] = MARK;
    }
}
/* I.S. k sembarang */
/* F.S. Terbentuk keranjang kosong dengan semua elemen bernilai MARK */

/* ********** SELEKTOR TAMBAHAN ********** */
int lengthKeranjang(KeranjangPisang k){
    int count = 0;
    int i = 0;
    // for(int i = 0; i<CAPACITY; i++){
    //     printf("%d\n",k.contents[i]);
    //     if(k.contents[i] = MARK){
    //         return count;
    //     }
    //     count++;
    // }
    while(i < CAPACITY && k.contents[i] != MARK){
        count++;
        i++;
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif keranjang */

IdxType getFirstIdx(KeranjangPisang k){
    return 0;
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(KeranjangPisang k){
    return lengthKeranjang(k)-1;
}
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(KeranjangPisang k, IdxType i){
    return (i >= 0 && i<CAPACITY);
}
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(KeranjangPisang k, IdxType i){
    return (i>=0 && i<lengthKeranjang(k));
}
/* Mengirimkan true jika i adalah indeks efektif dalam keranjang */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(KeranjangPisang k){
    return lengthKeranjang(k) == 0;
}
/* Mengirimkan true jika keranjang kosong */

boolean isFull(KeranjangPisang k){
    return lengthKeranjang(k) == CAPACITY;
}
/* Mengirimkan true jika keranjang penuh */

/* ********** BACA / TULIS ********** */
void readKeranjang(KeranjangPisang *k){
    int n;
    scanf("%d", &n);
    CreateKeranjang(k);
    for(int i = 0; i<n; i++){
        scanf("%d", &k->contents[i]);
        getchar();
    }
}
/* I.S. Sembarang */
/* F.S. Keranjang berisi n elemen hasil input (0 <= n <= CAPACITY) */
/* Format input: n diikuti n buah elemen */
/* Contoh: 3 10 20 30*/
/* n = 3 dengan elemen keranjang adalah 10,20,dan 30*/

void printKeranjang(KeranjangPisang k){
    int neff = lengthKeranjang(k);
    printf("[");
    for(int i = 0; i<neff; i++){
        printf("%d", k.contents[i]);
        if(i<neff-1){
            printf(",");
        }
    }
    printf("]\n");
}
/* Menampilkan isi keranjang dalam format [x1,x2,...,xn] */
/* Contoh : */
/* [10,20,30] */
/* Jika kosong : []*/

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */

void insertAt(KeranjangPisang *k, ElType val, IdxType idx){
    int neff = lengthKeranjang(*k);
    for (int i = neff; i>idx; i--){
        k->contents[i] = k->contents[i-1];
    }
    k->contents[idx] = val;
}
/* Menambahkan val di indeks tertentu */

void insertFirst(KeranjangPisang *k, ElType val){
    insertAt(k,val,0);
}
/* Menambahkan val sebagai elemen pertama */

void insertLast(KeranjangPisang *k, ElType val){
    insertAt(k, val, lengthKeranjang(*k));
}
/* Menambahkan val sebagai elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx){
    int neff = lengthKeranjang(*k);
    *val = k->contents[idx];
    for(int i = idx; i<neff; i++){
        k->contents[i] = k->contents[i+1];
    }
}
/* Menghapus elemen di indeks tertentu */

void deleteFirst(KeranjangPisang *k, ElType *val){
    *val = k->contents[0];
    deleteAt(k, val, 0);
}
/* Menghapus elemen pertama */



void deleteLast(KeranjangPisang *k, ElType *val){
    *val = k->contents[lengthKeranjang(*k)-1];
    k->contents[lengthKeranjang(*k)-1] = MARK;
}
/* Menghapus elemen terakhir */

// int main(){
//     KeranjangPisang k;
//     readKeranjang(&k);
//     printf("%d\n",lengthKeranjang(k));
//     printKeranjang(k);

// }
