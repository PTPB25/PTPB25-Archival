// NIM    : <Tulis NIM Anda>
// Nama   : <Tulis Nama Anda>
// Tanggal: <Tulis tanggal pengerjaan>

#ifndef MEGA_NIMONS_H
#define MEGA_NIMONS_H

#include "Boolean.h"

/* *** Konstanta *** */
#define CAPACITY 100
#define IDX_UNDEF -1

/* *** Type Data *** */
typedef int IdxType;

/* Struktur MegaNimons */
typedef struct {
    int id;                         // ID eksperimen unik
    char name[30];                  // Nama MegaNimons
    float powerLevel;              // Power level maksimum MegaNimons
    char mutationType[20];         // Tipe mutasi (contoh: "fly", "laser", dsb.)
    boolean isStable;              // TRUE kalau stable, FALSE kalau unstable
} MegaNimons;

/* Struktur LabTrack */
typedef struct {
    MegaNimons contents[CAPACITY]; // Tempat penyimpanan data MegaNimons
    int nEff;                      // Jumlah elemen efektif dalam list
} LabTrack;

/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah LabTrack:
 *   - L.contents[i] mengakses MegaNimons ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

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

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list MegaNimons
 * Format: [index]: ID=xxx NAME=xxx POWER=xxx.x MUT=xxx STABLE=Yes/No
 */
void printLabTrack(LabTrack L);

/**
 * Menghapus seluruh MegaNimons yang tidak stabil (isStable == false)
 * Setiap MegaNimons yang dihapus akan dicetak namanya ke layar
 * Format output: "EJECTED: <nama_minion>"
 * I.S. L terdefinisi
 * F.S. Semua MegaNimons tidak stabil dihapus dari list dan ditampilkan namanya
 */
void ejectUnstable(LabTrack *L);

/**
 * Menampilkan hanya MegaNimons dengan powerLevel >= minPower
 */
void filterByPower(LabTrack L, float minPower);

#endif