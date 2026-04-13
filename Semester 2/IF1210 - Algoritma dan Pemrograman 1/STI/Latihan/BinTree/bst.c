#include <stdio.h>
#include "bst.h"

/* ********* KONSTRUKTOR DAN DEALOKASI ********* */
/* Mengalokasikan sebuah simpul baru dengan info x */
Address newTreeNode(ElType x){
    Address new = malloc(sizeof(TreeNode));
    if(new == NIL) return NIL;

    new->info = x;
    new->left = NIL;
    new->right = NIL;
    return new;
}
/* I.S. Sembarang
   F.S. Menghasilkan address simpul baru dengan info = x serta anak kiri dan
   kanan = NIL Return NIL jika alokasi gagal */

/* Mengembalikan address p ke sistem */
void deallocTreeNode(Address p){
    if(p!=NIL) free(p);
}
/* I.S. p terdefinisi
   F.S. p didealokasi (free) */

/* ********* PREDIKAT PENTING ********* */
/* Mengirimkan true jika p adalah pohon kosong */
boolean isTreeEmpty(BinTree p){
    return p == NIL;
}

/* Mengirimkan true jika p hanya terdiri dari satu simpul
   anak kiri dan kanan bernilai NIL */
boolean isOneElmt(BinTree p){
    if(p==NIL) return false;
    return (p!=NIL && p->left == NIL && p->right == NIL);
}

/* Mengirimkan true jika p hanya memiliki anak kiri */
boolean isUnerLeft(BinTree p){
    if(p==NIL) return false;
    return (p->left != NIL && p->right == NIL);
}

/* Mengirimkan true jika p hanya memiliki anak kanan */
boolean isUnerRight(BinTree p){
    if(p==NIL) return false;
    return (p->left == NIL && p->right != NIL);
}

/* Mengirimkan true jika p memiliki dua anak */
boolean isBiner(BinTree p){
    if(p==NIL) return false;
    return (p->left != NIL && p->right != NIL);
}

/* ********* PEMBENTUK TREE ********* */
/* Membentuk pohon seimbang dari n simpul dengan input x per simpul */
BinTree buildBalancedTree(int n){
    if(n == 0) return NIL;
    ElType x;
    scanf("%d", &x.key);
    x.count = 1;
    BinTree root = newTreeNode(x);
    if(root == NIL) return NIL;

    int nL = n/2;
    int nR = n- nL -1;
    BinTree leftSub = buildBalancedTree(nL);

    root->left = leftSub;
    root->right = buildBalancedTree(nR);
    
    return root;
}
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
void insSearchTree(ElType x, BinTree *p){
    if(isTreeEmpty(*p)){
         *p = newTreeNode(x);
    }
    else if(x.key == ROOT(*p).key) {
        ROOT(*p).count++;
    }
    else if(x.key < ROOT(*p).key) {
        return insSearchTree(x, &LEFT(*p));
    }
    else if(x.key > ROOT(*p).key){
        return insSearchTree(x, &RIGHT(*p));
    }

}
/* I.S. p mungkin kosong, x terdefinisi
   F.S. Jika x.key sudah ada di p, maka count bertambah
        Jika belum ada, simpul baru ditambahkan di tempat sesuai properti BST
        - Jika pohon kosong, buat node baru
        - Semua simpul pada subpohon kiri < akar p
        - Semua simpul pada subpohon kanan >= akar p */

/* Prosedur pembantu untuk menghapus node maksimum dari subtree kiri */
void delNode(BinTree *p){
    if(isTreeEmpty(*p)) return;

    if(RIGHT(*p) != NIL){
        delNode(&RIGHT(*p));
    }   
    else{
        Address temp = *p;
        *p = LEFT(*p);
        deallocTreeNode(temp);
    }
}
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
void delBTree(BinTree *p, ElType x){

    if(x.key < ROOT(*p).key) delBTree(&LEFT(*p), x);
    else if(x.key > ROOT(*p).key) delBTree(&RIGHT(*p),x);
    else{
        if(isOneElmt(*p)){
            deallocTreeNode(*p);
            *p = NIL;
        }
        else if(isUnerLeft(*p)) {
            Address temp = *p;
            *p = LEFT(*p);
            deallocTreeNode(temp);
        }
        else if(isUnerRight(*p)){
            Address temp = *p;
            *p = RIGHT(*p);
            deallocTreeNode(temp);
        }
        else if(isBiner(*p)) {
            Address temp = LEFT(*p);
            while(RIGHT(temp) != NIL){
                temp = RIGHT(temp);
            }
            ROOT(*p) = temp->info;
            delNode(&LEFT(*p));
        }
    }
}
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
Address searchNode(BinTree p, int value){
    if(isTreeEmpty(p)) return NIL;

    if(value == ROOT(p).key) return p;
    else if(value < ROOT(p).key) return searchNode(LEFT(p), value);
    else return searchNode(RIGHT(p), value);
    return NIL;
}
/* I.S. p mungkin kosong, value terdefinisi
   F.S. Mengembalikan address node dengan key = value jika ditemukan,
        mengembalikan NIL jika tidak ditemukan */

/* Mencari node dengan nilai minimum dalam BST */
Address findMinimum(BinTree p){
    while(p->left != NIL){
        p = p->left;
    }
    return p;
}
/* I.S. p mungkin kosong
   F.S. Mengembalikan address node dengan nilai key minimum dalam BST,
        mengembalikan NIL jika pohon kosong */
