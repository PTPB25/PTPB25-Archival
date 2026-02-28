#include "bintree_traversal.h"
#include <stdio.h>

boolean search(BinTree p,int value){
   if(p == NIL) return false;

   if(p->info.key == value) return true;
   return  (search(p->left,value) || search(p->right, value));
}

int level(BinTree p, int value){
   if(p==NIL) return -1;

   if(p->info.key == value) return 1;
   if(p->left != NIL){
      int l = level(p->left, value);
      if(l!=-1) return l+1;
   }
   if(p->right !=NIL){
      int r = level(p->right, value);
      if(r!=-1) return r+1;
   }
   return -1;
}

/****************** FUNGSI TRAVERSAL TREE (PRINT) ******************/
/* Menampilkan elemen preorder: akar, kiri, kanan */
void printPreOrder(BinTree p){
    if(p == NULL) return;
    printf("%d ", p->info.key);
    printPreOrder(p->left);
    printPreOrder(p->right);
}
/* I.S. p terdefinisi
   F.S. Elemen ditampilkan sesuai urutan preorder, dipisah spasi, TANPA ENDLINE */

void printInOrder(BinTree p){
   if(p == NULL) return;
   printInOrder(p->left);
   printf("%d ", p->info.key);
   printInOrder(p->right);
}
/* Menampilkan elemen inorder: kiri, akar, kanan, TANPA ENDLINE */

void printPostOrder(BinTree p){
   if(p == NULL) return;
   printPostOrder(p->left);
   printPostOrder(p->right);
   printf("%d ", p->info.key);
}
/* Menampilkan elemen postorder: kiri, kanan, akar, TANPA ENDLINE */

/****************** FUNGSI PEMBENTUKAN LIST TRAVERSAL ******************/
/* Membuat node list baru dengan info = val dan next = NIL */
NodeList* newNodeListElement(ElType val){
   NodeList* new = malloc(sizeof(NodeList));
   if(new == NIL) return NIL;
   new->info = val;
   new->next = NIL;
   return new;
}
/* Mengalokasikan simpul baru untuk NodeList dengan nilai val
   Return NIL jika alokasi gagal */

NodeList* concat(NodeList* l1, NodeList* l2){
   if(l1 == NULL) return l2;

   NodeList* temp = l1;
   while(temp->next !=NIL) temp = temp->next;

   temp->next = l2;
   return l1;
}
/* I.S. l1 dan l2 adalah NodeList yang bisa kosong atau tidak
   F.S. l1 diikuti l2, mengembalikan list hasil konkatenasi */

/* Menghasilkan list preorder traversal dari pohon */
NodeList* makeListPreOrder(BinTree p){
   if(p == NIL) return NIL;

   NodeList* root = newNodeListElement(p->info);
   if(root == NIL) return NIL;

   NodeList* left = makeListPreOrder(p->left);
   NodeList* right = makeListPreOrder(p->right);

   NodeList* temp = concat(root, left);
   return concat(temp,right);
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList preorder traversal dari p (jika semua alokasi berhasil),
        atau NIL jika ada alokasi gagal */

/* Menghasilkan list inorder traversal dari pohon */
NodeList* makeListInOrder(BinTree p){
   if(p == NIL) return NIL;

   NodeList* left = makeListInOrder(p->left);
   NodeList* root = newNodeListElement(p->info);
   if(root == NIL) return NIL;
   NodeList* right = makeListInOrder(p->right);

   NodeList* temp = concat(left, root);
   return concat(temp,right);
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList inorder traversal dari p */

/* Menghasilkan list postorder traversal dari pohon */
NodeList* makeListPostOrder(BinTree p){
   if(p == NIL) return NIL;

   NodeList* left = makeListPostOrder(p->left);
   NodeList* right = makeListPostOrder(p->right);
   NodeList* root = newNodeListElement(p->info);
   if(root == NIL) return NIL;
   

   NodeList* temp = concat(left, right);
   return concat(temp,root);
}
/* I.S. p terdefinisi
   F.S. Menghasilkan NodeList postorder traversal dari p */

/* Menampilkan isi NodeList ke layar */
void printNodeList(NodeList* l){
   NodeList* current = l;
    while (current != NULL) {
        printf("[%d] -> ", current->info.key);
        current = current->next;
    }
    printf("FINISH\n");
}
/* I.S. l mungkin kosong atau tidak
   F.S. Seluruh elemen list ditampilkan dalam format linked list eksplisit
        Misalnya ada 3 elemen: 10, 20, dan 50 maka output:
        [10] -> [20] -> [50] -> FINISH
        Akhiri output dengan endline */

