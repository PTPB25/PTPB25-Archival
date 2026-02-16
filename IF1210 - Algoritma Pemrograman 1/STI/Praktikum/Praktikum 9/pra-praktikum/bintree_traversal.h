// NIM     : <Tulis NIM Anda>
// NAMA    : <Tulis Nama Anda>
// Tanggal : <Tulis tanggal pra praktikum>

#ifndef BINARY_TREE_TRAVERSAL_H
#define BINARY_TREE_TRAVERSAL_H
#include "bst.h"

/* *** Definisi Tipe NodeList *** */
typedef struct nodeList* AddressList;
typedef struct nodeList {
    ElType info;
    AddressList next;
} NodeList;

/* ********* AKSES (Selektor) ********* */
#define Info(L) (L)->info
#define Next(L) (L)->next

/****************** FUNGSI TRAVERSAL TREE (PRINT) ******************/
/* Menampilkan elemen preorder: akar, kiri, kanan */
void printPreOrder(BinTree p);
/* I.S. p terdefinisi
   F.S. Elemen ditampilkan sesuai urutan preorder, dipisah spasi, TANPA ENDLINE */

void printInOrder(BinTree p);
/* Menampilkan elemen inorder: kiri, akar, kanan, TANPA ENDLINE */

void printPostOrder(BinTree p);
/* Menampilkan elemen postorder: kiri, kanan, akar, TANPA ENDLINE */

/****************** FUNGSI PEMBENTUKAN LIST TRAVERSAL ******************/
/* Membuat node list baru dengan info = val dan next = NIL */
NodeList* newNodeListElement(ElType val);
/* Mengalokasikan simpul baru untuk NodeList dengan nilai val
   Return NIL jika alokasi gagal */

NodeList* concat(NodeList* l1, NodeList* l2);
/* I.S. l1 dan l2 adalah NodeList yang bisa kosong atau tidak
   F.S. l1 diikuti l2, mengembalikan list hasil konkatenasi */

/* Menghasilkan list preorder traversal dari pohon */
NodeList* makeListPreOrder(BinTree p);
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList preorder traversal dari p (jika semua alokasi berhasil),
        atau NIL jika ada alokasi gagal */

/* Menghasilkan list inorder traversal dari pohon */
NodeList* makeListInOrder(BinTree p);
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList inorder traversal dari p */

/* Menghasilkan list postorder traversal dari pohon */
NodeList* makeListPostOrder(BinTree p);
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList postorder traversal dari p */

/* Menampilkan isi NodeList ke layar */
void printNodeList(NodeList* l);
/* I.S. l mungkin kosong atau tidak
   F.S. Seluruh elemen list ditampilkan dalam format linked list eksplisit
        Misalnya ada 3 elemen: 10, 20, dan 50 maka output:
        [10] -> [20] -> [50] -> FINISH
        Akhiri output dengan endline */

#endif