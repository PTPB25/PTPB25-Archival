#ifndef BST_H
#define BST_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Definisi Tipe TreeNode dengan info berupa ElType bertipe Map (Key dan
 * Count) *** */
typedef struct {
    int key;
    int count;
} ElType;

typedef struct treeNode *Address;
typedef struct treeNode {
    ElType info;
    Address left;
    Address right;
} TreeNode;

typedef Address BinTree;

#define NIL NULL

/* ********* AKSES (Selektor) ********* */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

/* ********* KONSTRUKTOR DAN DEALOKASI ********* */
/* Mengalokasikan sebuah simpul baru dengan info x */
Address newTreeNode(ElType x);
/* I.S. Sembarang
   F.S. Menghasilkan address simpul baru dengan info = x serta anak kiri dan
   kanan = NIL Return NIL jika alokasi gagal */

/* Mengembalikan address p ke sistem */
void deallocTreeNode(Address p);
/* I.S. p terdefinisi
   F.S. p didealokasi (free) */

/* ********* PREDIKAT PENTING ********* */
/* Mengirimkan true jika p adalah pohon kosong */
boolean isTreeEmpty(BinTree p);

/* Mengirimkan true jika p hanya terdiri dari satu simpul
   anak kiri dan kanan bernilai NIL */
boolean isOneElmt(BinTree p);

/* Mengirimkan true jika p hanya memiliki anak kiri */
boolean isUnerLeft(BinTree p);

/* Mengirimkan true jika p hanya memiliki anak kanan */
boolean isUnerRight(BinTree p);

/* Mengirimkan true jika p memiliki dua anak */
boolean isBiner(BinTree p);

/* ********* PEMBENTUK TREE ********* */
/* Membentuk pohon seimbang dari n simpul dengan input x per simpul */
BinTree buildBalancedTree(int n);
/* I.S. n ≥ 0
   F.S. Menghasilkan pohon biner seimbang dengan n simpul,
        setiap simpul diisi dengan input nilai key dan count = 1
   Proses:
      - Jika n = 0, return NIL
      - Setiap simpul diisi dengan input x.key dan count = 1
      - Jumlah simpul anak kiri (nL) = n div 2
      - Jumlah simpul anak kanan(nR) = n - nL - 1
      - Simpul kiri akan direkursif dengan n = nL
      - Simpul kanan akan direkursif dengan n = nR
      - Return nilai root paling atas */

/* ********* OPERASI BST ********* */
/* Menyisipkan x ke dalam BST p */
void insSearchTree(ElType x, BinTree *p);
/* I.S. p mungkin kosong, x terdefinisi
   F.S. Jika x.key sudah ada di p, maka count bertambah
        Jika belum ada, simpul baru ditambahkan di tempat sesuai properti BST
        - Jika pohon kosong, buat node baru
        - Semua simpul pada subpohon kiri < akar p
        - Semua simpul pada subpohon kanan >= akar p */

/* Prosedur pembantu untuk menghapus node maksimum dari subtree kiri */
void delNode(BinTree *p);
/* I.S. *p menunjuk ke subtree kiri dari simpul yang ingin digantikan (p tidak
 * kosong) */
/* F.S. Node paling kanan dari subtree kiri (nilai maksimum) dihapus dari pohon,
         dan anak kirinya (jika ada) dinaikkan menggantikannya */
/* Proses:
   - Jika RIGHT(*p) ≠ NIL, lanjut ke kanan (rekursif)
   - Jika RIGHT(*p) = NIL, berarti node saat ini adalah node maksimum
     → *p digantikan dengan anak kirinya (bisa NIL)
     → node tersebut didealokasi */

/* Menghapus simpul dengan key = x.key dari Binary Search Tree */
void delBTree(BinTree *p, ElType x);
/* I.S. *p menunjuk ke root dari subtree yang sedang diperiksa,
        x.key pasti ada dalam BST */
/* F.S. Simpul dengan nilai key = x.key dihapus dari BST,
        struktur dan sifat BST tetap dipertahankan */
/* Proses:
   - Jika x.key < key node saat ini → rekursif ke kiri
   - Jika x.key > key node saat ini → rekursif ke kanan
   - Jika x.key = key node saat ini:
       - Jika node adalah daun (leaf) → langsung hapus
       - Jika hanya memiliki satu anak → naikkan anak ke atas
       - Jika memiliki dua anak:
           - Cari nilai maksimum di subtree kiri (RIGHT-most dari LEFT(*p))
           - Salin info dari node maksimum ke node saat ini
           - Hapus node maksimum tersebut (dengan delNode) */

/* Mencari node dengan key = value dalam BST */
Address searchNode(BinTree p, int value);
/* I.S. p mungkin kosong, value terdefinisi
   F.S. Mengembalikan address node dengan key = value jika ditemukan,
        mengembalikan NIL jika tidak ditemukan */

/* Mencari node dengan nilai minimum dalam BST */
Address findMinimum(BinTree p);
/* I.S. p mungkin kosong
   F.S. Mengembalikan address node dengan nilai key minimum dalam BST,
        mengembalikan NIL jika pohon kosong */

#endif