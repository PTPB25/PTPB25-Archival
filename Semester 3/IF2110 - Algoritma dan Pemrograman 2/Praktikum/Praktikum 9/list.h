/* File: list.h */
/* Definisi List Rekursif dan Metode - Metode Terkait*/

#ifndef LIST_H
#define LIST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

#define NIL NULL

/* Definisi tipe elemen dan struktur list rekursif */
typedef int ElType;
typedef struct node *Address;
typedef struct node {
    ElType info;
    Address next;
} Node;

typedef Address List;

/* *** Selektor *** */
#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/* *** Manajemen Memori *** */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya menghasilkan p,
   maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
Address newNode(ElType x);

/* *** Pemeriksaan Kondisi List *** */
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
boolean isEmpty(List l);

/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong
 */
boolean isOneElmt(List l);

/* *** Primitif Pemrosesan List *** */

/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
ElType head(List l);

/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong
 */
List tail(List l);

/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya.
   Jika alokasi gagal, mengirimkan l */
List konso(ElType e, List l);

/* Mengirimkan list l dengan tambahan e sebagai elemen terakhir.
   Jika alokasi gagal, mengirimkan l */
List konsDot(List l, ElType e);

/* *** Operasi dan Fungsi Lain *** */

/* Menampilkan seluruh elemen list ke layar secara rekursif */
void displayList(List l);

/* Mengirimkan banyaknya elemen list l, Nol jika l kosong */
int length(List l);

/* Mengirimkan true jika x adalah anggota list, false jika tidak */
boolean search(List l, ElType x);

/* Menghapus semua elemen list yang bernilai x */
void deleteX(List *l, ElType x);

/* Mengirimkan salinan list l. Jika alokasi gagal, mengirimkan l. */
List copy(List l);

/* Menyalin isi list lin ke lout */
void mCopy(List lin, List *lout);

/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 */
List concat(List l1, List l2);

/* Menghasilkan salinan hasil konkatenasi l1 dan l2 melalui parameter result */
void mConcat(List l1, List l2, List *result);

#endif
