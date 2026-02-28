#ifndef MEGA_NIMONS_H
#define MEGA_NIMONS_H

#include "boolean.h"

#define CAPACITY 100
#define IDX_UNDEF -1

typedef int IdxType;

typedef struct {
    int id;
    char name[30];
    float powerLevel;
    char mutationType[20];
    boolean isStable;
} MegaNimons;

typedef struct {
    MegaNimons contents[CAPACITY];
    int nEff;
} LabTrack;

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createLabTrack(LabTrack *L);

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(LabTrack L);

/**
 * Mengembalikan kapasitas maksimum list
 */
int maxCapacity();

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType firstIdx(LabTrack L);

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType lastIdx(LabTrack L);

/**
 * Mengembalikan MegaNimons pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
MegaNimons getElmt(LabTrack L, IdxType i);

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(LabTrack *L, IdxType i, MegaNimons val);

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(LabTrack *L, int N);

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i);

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(LabTrack L, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(LabTrack L);

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(LabTrack L);

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan MegaNimons pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(LabTrack *L, MegaNimons m, IdxType idx);

/**
 * Menambahkan MegaNimons ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(LabTrack *L, MegaNimons m);

/**
 * Menambahkan MegaNimons ke posisi terakhir dalam list
 */
void insertLast(LabTrack *L, MegaNimons m);

/**
 * Menghapus MegaNimons pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m);

/**
 * Menghapus MegaNimons pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteFirst(LabTrack *L, MegaNimons *m);

/**
 * Menghapus MegaNimons pada indeks terakhir
 * Elemen terakhir disimpan pada *m
 */
void deleteLast(LabTrack *L, MegaNimons *m);

/**
 * Mengembalikan indeks MegaNimons berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(LabTrack L, int id);

/* === Utility & Analysis Functions === */

/**
 * Menampilkan seluruh isi list MegaNimons
 * Format: [index]: ID=xxx NAME=xxx POWER=xxx.x MUT=xxx STABLE=Yes/No
 */
void printLabTrack(LabTrack L);

/* Mengembalikan true jika power level m1 dan m2 sama (dalam toleransi kecil, jika perlu) */
boolean isPowerEqual(MegaNimons m1, MegaNimons m2);

/* Mengembalikan true jika m1 lebih stabil dari m2 */
boolean isMoreStable(MegaNimons m1, MegaNimons m2);

/* Mengembalikan pemenang antara dua MegaNimons berdasarkan aturan:
   - powerLevel lebih tinggi menang
   - Jika powerLevel sama, yang lebih stabil menang
   - Jika sama-sama stabil atau tidak stabil, ID lebih kecil menang */
MegaNimons resolveDuel(MegaNimons m1, MegaNimons m2);

/**
 * Melakukan satu kali duel antara dua MegaNimons dan mencetak hasilnya ke layar.
 * Duel ditentukan berdasarkan aturan resolveDuel
 *
 * I.S. m1 dan m2 terdefinisi
 * F.S. Tercetak deskripsi duel dan nama pemenangnya ke layar
 *
 * Contoh output:
 *   Duel: Super-Daev (888.5) vs Bobzilla (777.7)
 *   Winner: Super-Daev
 * 
 * Pastikan setiap output selalu diakhiri endline ("\n")!
 */
void duelOnce(MegaNimons m1, MegaNimons m2);

#endif