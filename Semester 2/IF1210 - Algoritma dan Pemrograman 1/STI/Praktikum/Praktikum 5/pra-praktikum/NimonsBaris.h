#include "Boolean.h"

#ifndef NIMONSBARIS_H
#define NIMONSBARIS_H

/* Kamus Umum */

#define IdxMax 100
#define IdxMin 1
#define IdxUndef -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType; // Index Type
typedef int ElType;  // Element Type

typedef struct
{
    ElType baris[IdxMax - IdxMin + 1]; /* memori tempat penyimpan elemen (container) */
    int Neff;                          /* banyaknya elemen efektif (banyak nimons di barisan) */
} BarisanNimons;

/**
 * Indeks yang digunakan [IdxMin..IdxMax]
 * Jika T adalah BarisanNimons, cara deklarasi dan akses:
 * Deklarasi -> T : BarisanNimons
 *
 * Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.baris untuk mengakses seluruh nilai elemen tabel
 * T.baris[i] untuk mengakses elemen ke-i
 *
 * Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.baris[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.baris[i] dengan i=T.Neff
 */

/* ********** KONSTRUKTOR ********** */
/**
 * Konstruktor : create tabel kosong
 * I.S. sembarang
 * F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1
 */
void MakeEmpty(BarisanNimons *T);

/* ********** SELEKTOR ********** */
/** --- Banyaknya elemen ---
 * Mengirimkan banyaknya elemen efektif tabel
 * Mengirimkan nol jika tabel kosong
 */
int NbElmt(BarisanNimons T);

/** --- Daya tampung container ---
 * Mengirimkan maksimum elemen yang dapat ditampung oleh tabel
 */
int MaxNbEl(BarisanNimons T);

/* --- Selektor INDEKS --- */
/**
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen pertama
 */
IdxType GetFirstIdx(BarisanNimons T);
/**
 * Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks elemen terakhir
 */
IdxType GetLastIdx(BarisanNimons T);

/* --- Menghasilkan sebuah elemen --- */
/**
 * Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T)
 * Mengirimkan elemen tabel yang ke-i
 */
ElType GetElmt(BarisanNimons T, IdxType i);

/* --- Selektor SET : Mengubah nilai TABEL dan elemen tabel --- */
/**
 * Untuk type private/limited private pada bahasa tertentu
 * I.S. Tin terdefinisi, sembarang
 * F.S. Tout berisi salinan Tin
 * Assignment THsl -> Tin
 */
void SetTab(BarisanNimons Tin, BarisanNimons *Tout);

/**
 * I.S. T terdefinisi, sembarang
 * F.S.Elemen T yang ke - i bernilai v
 * Mengeset nilai elemen tabel yang ke - i sehingga bernilai v
 */
void SetEl(BarisanNimons *T, IdxType i, ElType v);

/**
 * I.S. T terdefinisi, sembarang
 * F.S. Nilai indeks efektif T bernilai N
 * Mengeset nilai indeks elemen efektif sehingga bernilai N
 */
void SetNeff(BarisanNimons *T, IdxType N);

/* ********** Test Indeks yang valid ********** */
/**
 * Prekondisi : i sembarang
 * Mengirimkan TRUE jika i adalah indeks yang valid utk ukuran tabel
 * yaitu antara indeks yang terdefinisi utk container
 */
boolean IsIdxValid(BarisanNimons T, IdxType i);
/**
 * Prekondisi : i sembarang
 * Mengirimkan TRUE jika i adalah indeks yang terdefinisi utk tabel
 * yaitu antara FirstIdx(T)..LastIdx(T)
 */
boolean IsIdxEff(BarisanNimons T, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */

/* --- Test tabel kosong --- */
/* Mengirimkan TRUE jika tabel T kosong, mengirimkan FALSE jika tidak */
boolean IsEmpty(BarisanNimons T);
/* --- Test tabel penuh --- */
/* Mengirimkan TRUE jika tabel T penuh, mengirimkan FALSE jika tidak */
boolean IsFull(BarisanNimons T);

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/**
 * Proses : Menuliskan isi tabel dengan traversal
 * I.S. T boleh kosong
 * F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah
 * Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
 * Jika T kosong : Hanya menulis "Tabel kosong"
 */
void TulisIsi(BarisanNimons T);

/* ********** OPERATOR ARITMATIKA ********** */
/* --- Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... --- */
/** Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
 * Mengirimkan T1 + T2
 */
BarisanNimons PlusTab(BarisanNimons T1, BarisanNimons T2);
/** Prekondisi : T1 dan T2 berukuran sama dan tidak kosong
 * Mengirimkan T1 - T2
 */
BarisanNimons MinusTab(BarisanNimons T1, BarisanNimons T2);

/* ********** NILAI EKSTREM ********** */
/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan nilai maksimum tabel
 */
ElType ValMax(BarisanNimons T);

/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan nilai minimum tabel
 */
ElType ValMin(BarisanNimons T);

/* --- Mengirimkan indeks elemen bernilai ekstrem --- */
/** Prekondisi : Tabel T tidak kosong
 * Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel
 */
IdxType IdxMaxTab(BarisanNimons T);

/** Prekondisi : Tabel tidak kosong
 * Mengirimkan indeks i
 * dengan elemen ke-i nilai minimum pada tabel
 */
IdxType IdxMinTab(BarisanNimons T);

#endif