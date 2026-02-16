/* MODUL LIST NIMONS STATIK */
/* Berisi definisi dan semua primitif pemrosesan list statik untuk menyimpan data Nimons */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTNIMONS_H
#define LISTNIMONS_H

#include "Boolean.h"

/*  Kamus Umum */
#define NIMONS_CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1

/* Definisi elemen dan koleksi objek */
typedef struct
{
    char name[21]; // nama Nimons, maksimal 20 karakter
    int age;       // umur Nimons
    int height;    // tinggi badan dalam cm
} Nimons;

typedef struct
{
    Nimons contents[NIMONS_CAPACITY];
} ListNimons;

/* Definisi Nimons kosong: name adalah string kosong ("") atau age = -1 */

/* ********** SELEKTOR ********** */
#define ELMT_NIMONS(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
void CreateListNimons(ListNimons *l);
/* I.S. l sembarang */
/* F.S. Terbentuk ListNimons l kosong dengan semua elemen memiliki name kosong dan age = -1 */

/* ********** SELEKTOR TAMBAHAN ********** */
int listNimonsLength(ListNimons l);
/* Mengirimkan banyaknya elemen efektif ListNimons */
/* Mengirimkan nol jika List kosong */

boolean isIdxValidNimons(ListNimons l, int i);
/* Mengirimkan true jika i adalah indeks yang valid untuk kapasitas list */

boolean isIdxEffNimons(ListNimons l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi dalam list (0..length-1) */

boolean isNimonsEmpty(ListNimons l);
/* Mengirimkan true jika ListNimons kosong */

boolean isNimonsFull(ListNimons l);
/* Mengirimkan true jika ListNimons penuh */

/* ********** BACA dan TULIS ********** */
void readNimonsList(ListNimons *l);
/* I.S. l sembarang */
/* F.S. ListNimons l berisi n data Nimons hasil pembacaan dari user */
/* Format: nama umur tinggi, misalnya: Bob 8 100 */

void printNimonsList(ListNimons l);
/* Proses : Menuliskan isi ListNimons dalam format:
   [name1-age1-height1, name2-age2-height2, ..., nameN-ageN-heightN] */

/* ********** MENAMBAH dan MENGHAPUS ********** */
void insertNimonsLast(ListNimons *l, Nimons m);
/* Menambahkan Nimons m sebagai elemen terakhir */

void deleteNimonsLast(ListNimons *l, Nimons *m);
/* Menghapus elemen terakhir list dan menyimpan ke *m */

/* ********** SEARCHING ********** */
int indexOfNimons(ListNimons l, char *name);
/* Mencari nama Nimons dalam list.
   Mengembalikan indeks pertama yang cocok, atau IDX_UNDEF jika tidak ditemukan */

/* ********** NILAI EKSTREM ********** */
void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest);
/* Menentukan Nimons dengan tinggi tertinggi dan terendah dari list */

#endif