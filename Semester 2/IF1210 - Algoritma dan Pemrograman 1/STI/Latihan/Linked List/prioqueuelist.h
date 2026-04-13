#ifndef _PRIOQUEUELIST_H
#define _PRIOQUEUELIST_H
#include "boolean.h"
#include <stdlib.h>
#define Nil NULL
/* Deklarasi type elemen */
typedef int ElType;
/* Priority Queue dengan representasi berkait dengan pointer */
typedef struct tNode *Address;
typedef struct tNode {
ElType info;
int prio;
Address next;
} Node;
/* Type PrioQueue dengan HEAD */
typedef struct {
Address addrHead; /* alamat elemen pertama */
} PrioQueue;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info
#define PRIO(p) (p)->prio
#define ADDR_HEAD(q) (q).addrHead
#define HEAD(q) (q).addrHead->info
/* Prototype manajemen memori */
Address newNode(ElType x, int pr);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x dan prio = pr,
atau NIL jika alokasi gagal */
void delNode(Address *P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */

boolean isEmpty(PrioQueue q);
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NIL and ADDR_TAIL(q)=NIL */
int length(PrioQueue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
/*** Kreator ***/
void CreateQueue(PrioQueue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
/*** Primitif Enqueue/Dequeue ***/
void enqueue(PrioQueue *q, ElType x, int pr);
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q
jika alokasi berhasil; jika alokasi gagal q tetap */
/* I.S. q mungkin kosong */
/* F.S. x menjadi elemen q sesuai dengan urutan prioritas */
void dequeue(PrioQueue *q, ElType *x, int *pr);
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
#endif