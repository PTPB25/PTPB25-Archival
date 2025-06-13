
#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

Address newNode(ElType val){
    Address node = (Address) malloc(sizeof(Node));
    INFO(node) = val;
    NEXT(node) = NULL;
    return node;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    Address address = FIRST(l);
    while(idx > 0){
        address = NEXT(address);
        idx--;
    }
    return INFO(address);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    Address address = FIRST(*l);
    while(idx > 0){
        address = NEXT(address);
        idx--;
    }
    INFO(address) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address address = FIRST(l);
    int idx = 0;
    while(address != NULL && INFO(address) != val){
        address = NEXT(address);
        idx++;
    }
    if(address != NULL){
        return idx; 
    }
    return IDX_UNDEF;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address new = newNode(val);
    if(new != NULL){
        if(isEmpty(*l)){
            *l = new;
        }
        else{
            NEXT(new) = *l;
            *l = new;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address new = newNode(val);
    if(new != NULL){
        if(isEmpty(*l)){
            *l = new;
        }
        else{
            Address curr = *l;
            while(NEXT(curr) != NULL){
                curr = NEXT(curr);
            }
            NEXT(curr) = new;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    Address new = newNode(val);
    if(new != NULL){
        Address curr = *l;
        if(idx > 0){
            idx--;
            while(idx > 0){
                curr = NEXT(curr);
                idx--;
            }
            Address temp = NEXT(curr);
            NEXT(curr) = new;
            NEXT(new) = temp;
        }
        else{
            NEXT(new) = curr;
            *l = new;
        }
        
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address temp = *l;
    *val = INFO(*l);
    *l = NEXT(*l);
    free(temp);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address curr = *l;
    if(NEXT(curr) == NULL){
        *val = INFO(curr);
        free(curr);
        *l = NULL;
    }
    else{
        while(NEXT(NEXT(curr)) != NULL){
            curr = NEXT(curr);
        }
        Address temp = NEXT(curr);
        *val = INFO(NEXT(curr));
        NEXT(curr) = NULL;
        free(temp);
    }

}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    Address curr = *l;
    if(idx > 0){
        idx--;
        while(idx > 0){
            curr = NEXT(curr);
            idx--;
        }
        Address temp = NEXT(NEXT(curr));
        *val = INFO(NEXT(curr));
        free(NEXT(curr));
        NEXT(curr) = temp;
    }
    else{
        deleteFirst(l, val);
    }

}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address curr = l;
    printf("[");
    while(curr != NULL){
        if(NEXT(curr) == NULL){
            printf("%d", INFO(curr));
        }
        else{
            printf("%d,", INFO(curr));
        }
        curr = NEXT(curr);
    }
    printf("]");
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    Address curr = l;
    int n = 0;
    while(curr != NULL){
        curr = NEXT(curr);
        n++;
    }
    return n;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address curr;

    curr = l1;
    while(curr != NULL){
        insertLast(&l3, INFO(curr));
        curr = NEXT(curr);
    }

    curr = l2;
    while(curr != NULL){
        insertLast(&l3, INFO(curr));
        curr = NEXT(curr);
    }

    l1 = NULL;
    l2 = NULL;
    return l3;

}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
