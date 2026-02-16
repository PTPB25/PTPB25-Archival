// NIM     : <Tulis NIM Anda> ; <Tulis NIM partner Anda>
// NAMA    : <Tulis Nama Anda>; <Tulis Nama partner Anda>
// Tanggal : <Tulis tanggal praktikum>

/* MODUL PRIORITY QUEUE BERBASIS LINEAR BUFFER */
/* Digunakan untuk mengatur antrean penonton Festival Musik Gro */
/* Penonton akan diatur berdasarkan prioritas queueNumber (QN), dan dicegah agar tidak duplikat berdasarkan seatNumber (SN) */

#ifndef __tiket_konser_h__
#define __tiket_konser_h__

#include "boolean.h"

#define IDX_UNDEF -1
#define IDX_MAX 99

/* ********* Tipe Data Penonton (Elemen Queue) ********* */
typedef struct {
        char nama[50];     /* Nama penonton (Nimons) */
        int seatNumber;    /* SN: nomor unik tempat duduk */
        int queueNumber;   /* QN: semakin kecil → semakin depan antrean */
} Penonton;

/* Definisi tipe elemen dan indeks pada Queue */
typedef Penonton ElType;
typedef int IdxType;


/* ********* Definisi Queue Linear Buffer dengan representasi array secara eksplisit dan alokasi statik (Alternatif I) ********* */
typedef struct {
        ElType Tab[IDX_MAX+1];  /* tabel penyimpan elemen */
        IdxType idxHead;  /* indeks elemen paling awal (terdepan) */
        IdxType idxTail;  /* indeks tempat menambah elemen baru */
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue dan p adalah elemen Queue, maka akses elemen: */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).Tab[(q).idxHead]
#define     TAIL(q) (q).Tab[(q).idxTail]
#define     NAMA(p) (p).nama
#define       SN(p) (p).seatNumber
#define       QN(p) (p).queueNumber

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX */
int Length (Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue *Q);
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType P);
/* Proses: Menambahkan P ke dalam antrean jika dan hanya jika: */
/* - SN dari P belum pernah ada di antrean (tidak duplikat) */
/* - QN dari P menentukan posisi berdasarkan prioritas */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Apabila P memenuhi semua syarat, P masuk ke posisi yang sesuai berdasarkan queueNumber
        Semakin kecil, semakin berada di depan antrean
        IDX_TAIL akan "mundur" ke belakang */
ElType dequeue (Queue *Q);
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        jika Q belum kosong idxHead "tetap" di indeks 0 dan elemen akan digeser satu per satu
        Q mungkin kosong dan idxHead akan menjadi IDX_UNDEF */

/* *** Operasi Tambahan *** */
ElType peek (Queue Q);
/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */

boolean isDuplicateSN(Queue Q, int sn);
/* Mengirim true jika terdapat Penonton dalam antrean dengan SN yang sama */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [p1, p2, ..., pn] */
/* Contoh : jika ada tiga elemen bernilai "Kebin" dgn SN: 3 QN: 1, "Pop" dgn SN: 1 QN: 2, dan "Toto" dgn SN: 2 QN: 3 akan dicetak: [(Kebin-3-1), (Pop-1-2), (Toto-2-3)] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */

#endif