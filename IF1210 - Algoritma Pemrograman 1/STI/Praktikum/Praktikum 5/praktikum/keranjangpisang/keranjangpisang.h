/* MODUL KERANJANG PISANG - LIST STATIK TANPA SORTING/SEARCHING/ARITMATIKA */
/* Berisi definisi dan semua primitif pemrosesan list statik integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit dengan nilai MARK */

#ifndef KERANJANGPISANG_H
#define KERANJANGPISANG_H

#include "Boolean.h"

/*  Kamus Umum */
#define CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1
#define MARK -9999

/* Definisi elemen dan koleksi objek */
typedef int ElType;
typedef int IdxType;

typedef struct
{
    ElType contents[CAPACITY];
} KeranjangPisang;

#define ELMT(l, i) (l).contents[(i)]

/* Indeks yang digunakan [0..CAPACITY-1] */

/* ********** KONSTRUKTOR ********** */
void CreateKeranjang(KeranjangPisang *k);
/* I.S. k sembarang */
/* F.S. Terbentuk keranjang kosong dengan semua elemen bernilai MARK */

/* ********** SELEKTOR TAMBAHAN ********** */
int lengthKeranjang(KeranjangPisang k);
/* Mengirimkan banyaknya elemen efektif keranjang */

IdxType getFirstIdx(KeranjangPisang k);
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen pertama */

IdxType getLastIdx(KeranjangPisang k);
/* Prekondisi : k tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* ********** TEST INDEKS ********** */
boolean isIdxValid(KeranjangPisang k, IdxType i);
/* Mengirimkan true jika i adalah indeks valid untuk container */

boolean isIdxEff(KeranjangPisang k, IdxType i);
/* Mengirimkan true jika i adalah indeks efektif dalam keranjang */

/* ********** TEST KOSONG / PENUH ********** */
boolean isEmpty(KeranjangPisang k);
/* Mengirimkan true jika keranjang kosong */

boolean isFull(KeranjangPisang k);
/* Mengirimkan true jika keranjang penuh */

/* ********** BACA / TULIS ********** */
void readKeranjang(KeranjangPisang *k);
/* I.S. Sembarang */
/* F.S. Keranjang berisi n elemen hasil input (0 <= n <= CAPACITY) */
/* Format input: n diikuti n buah elemen */
/* Contoh: 3 10 20 30*/
/* n = 3 dengan elemen keranjang adalah 10,20,dan 30*/

void printKeranjang(KeranjangPisang k);
/* Menampilkan isi keranjang dalam format [x1,x2,...,xn] */
/* Contoh : */
/* [10,20,30] */
/* Jika kosong : []*/

/* ********** OPERASI PENAMBAHAN ELEMEN ********** */
void insertFirst(KeranjangPisang *k, ElType val);
/* Menambahkan val sebagai elemen pertama */

void insertAt(KeranjangPisang *k, ElType val, IdxType idx);
/* Menambahkan val di indeks tertentu */

void insertLast(KeranjangPisang *k, ElType val);
/* Menambahkan val sebagai elemen terakhir */

/* ********** OPERASI PENGHAPUSAN ELEMEN ********** */
void deleteFirst(KeranjangPisang *k, ElType *val);
/* Menghapus elemen pertama */

void deleteAt(KeranjangPisang *k, ElType *val, IdxType idx);
/* Menghapus elemen di indeks tertentu */

void deleteLast(KeranjangPisang *k, ElType *val);
/* Menghapus elemen terakhir */

#endif