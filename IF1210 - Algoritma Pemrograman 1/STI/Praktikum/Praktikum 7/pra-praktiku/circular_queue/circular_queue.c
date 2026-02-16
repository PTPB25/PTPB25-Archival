#include "circular_queue.h"
#include <stdio.h>
#include "boolean.h"

boolean IsEmpty (Queue Q){
    if (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF) return true;
    return false;
}
/* Mengirim true jika Q kosong */
/* yaitu ketika idxHead=IDX_UNDEF dan idxTail=IDX_UNDEF */
boolean IsFull (Queue Q){
    if((Q.idxHead == 0 && Q.idxTail == IDX_MAX) || (Q.idxHead > Q.idxTail  && Q.idxHead == Q.idxTail+1)){
        return true;
    }
    return false;
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu ketika idxHead=0 dan idxTail=IDX_MAX atau idxHead=idxTail+1 ketika idxHead > idxTail */
int Length (Queue Q){
    if (IsEmpty(Q)) {
        return 0;
    } else if (Q.idxHead <= Q.idxTail) {
        return Q.idxTail - Q.idxHead + 1;
    } else {
        return (IDX_MAX + 1) - Q.idxHead + Q.idxTail + 1;
    }
}
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */

/* *** Kreator *** */
void CreateQueue (Queue *Q){
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/* - idxHead=IDX_UNDEF; */
/* - idxTail=IDX_UNDEF. */

/* *** Primitif Add/Delete *** */
void enqueue (Queue *Q, ElType X){
    if(IsEmpty(*Q)){
        Q->idxHead = 0;
        Q->idxTail = 0;
        Q->Tab[0] = X;
    }else{
        Q->idxTail = (Q->idxTail+1)%(IDX_MAX+1);
        Q->Tab[Q->idxTail] = X;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. Tail "maju" dengan mekanisme circular buffer,
        X menjadi idxTail yang baru
        Jika Q kosong, idxHead dimulai dari 0 */
ElType dequeue (Queue *Q){
    ElType yes = Q->Tab[Q->idxHead];
        if(Q->idxHead == Q->idxTail){
            Q->idxHead = IDX_UNDEF;
            Q->idxTail = IDX_UNDEF;
        }else{
            Q->idxHead = (Q->idxHead+1)%(IDX_MAX+1);
        }
    return yes;
}
/* Proses: Menghapus idxHead pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada idxHead;
        Head "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* *** Operasi Tambahan *** */
ElType peek (Queue Q){
    return Q.Tab[Q.idxHead];
}
/* Proses : Mengembalikan elemen paling depan dari Queue tanpa menghapusnya */
/* I.S. Q tidak mungkin kosong */
/* F.S. Mengembalikan nilai pada idxHead */

/* *** Display Queue *** */
void displayQueue(Queue q){
    printf("[");
    if(!IsEmpty(q)){
        if (!IsEmpty(q)) {
            for (int i = q.idxHead; ; i = (i + 1) % (IDX_MAX + 1)) {
                printf("%s", q.Tab[i].namaTim);
                
                if (i == q.idxTail) {
                    break; // Exit when we've reached the tail
                }
                printf(", ");
            }
        }
        printf("]\n");
    }
}
/* Proses : Menuliskan isi Queue dengan traversal; Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma" dan "spasi" */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1, e2, ..., en] */
/* Contoh : jika ada tiga elemen bernilai "Tim_1", "Tim_2", dan "Tim_3" akan dicetak: [Tim_1, Tim_2, Tim_3] */
/* Jika Queue kosong : menulis [] */
/* Note: Output mengandung newline */