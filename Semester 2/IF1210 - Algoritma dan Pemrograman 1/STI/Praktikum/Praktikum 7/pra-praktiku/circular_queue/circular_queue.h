// NIM     : <Tulis NIM Anda>
// NAMA    : <Tulis Nama Anda>
// Tanggal : <Tulis tanggal pra praktikum>

/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_h__
#define __circular_queue_h__

#include "boolean.h"

#define IDX_UNDEF -1
#define IDX_MAX 99

typedef struct {
        char namaTim[50];  /* Nama Tim Pemadam Kebakaran */
} Tim;

/* Definisi tipe elemen dan indeks pada Queue */
typedef Tim ElType;
typedef int IdxType;

typedef struct {
        ElType Tab[IDX_MAX+1];  /* tabel penyimpan elemen */
        IdxType idxHead;  /* indeks elemen paling awal (terdepan) */
        IdxType idxTail;  /* indeks tempat menambah elemen baru */
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).Tab[(q).idxHead]
#define     TAIL(q) (q).Tab[(q).idxTail]

/* ********* Prototype ********* */
boolean IsEmpty (Queue Q);
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int Length (Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue *Q);
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType dequeue (Queue *Q);
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Operasi Tambahan *** */
ElType peek (Queue Q);
/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1, e2, ..., en] */
/* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */

#endif 