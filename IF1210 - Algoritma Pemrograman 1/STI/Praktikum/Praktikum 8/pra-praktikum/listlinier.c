#include <stdio.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L){
    return L.First == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L){
    L->First = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X){
    address p = malloc(sizeof(ElmtList));
    if(p != Nil){
        p->info = X;
        p->next = Nil;
    } 

    return p;
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P){
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X){
    boolean found = false;
    address p = L.First;

    while(p != Nil && !found ){
        if(p->info == X){
            found = true;
        }else{
            p = p->next;
        }
    }

    if(found) return p;
    else return Nil;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X){
    address p = Alokasi(X);

    if(p!=Nil){
        p->next = L->First;
        L->First = p;
    }
    return;
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X){
    if(IsEmpty(*L)){
        InsVFirst(L, X);
        return;
    }

    address p = Alokasi(X);
    if(p!=Nil){
        // int ctr = 0;
        address loc = L->First;
        while(loc->next != Nil){
            loc = loc->next;
        }

        loc->next = p;
    }
    return;
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X){
    *X = L->First->info;
    address p = L->First;
    L->First = L->First->next;
    free(p);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X){
    address loc = L->First;
    address p = Nil;

    while(loc->next != Nil){
        p = loc;
        loc = loc->next;
    }

    if(p == Nil){
        DelVFirst(L,X);
    }else{
        *X = loc->info;
        p->next = Nil;
        free(loc); 
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P){
    P->next = L->First;
    L->First = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (address P, address Prec){
    P->next = Prec->next;
    Prec->next = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P){
    address p = L->First;

    while(p->next != Nil){
        p = p->next;
    }

    p->next = P;
    P->next = Nil;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P){
    *P = L->First;
    // P->next = Nil; // error elmt list **
    L->First = L->First->next;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X){
    if(IsEmpty(*L)) return;
    if(L->First->next == Nil){
        address *temp = L->First;
        Dealokasi(temp);
        CreateEmpty(L);
    }else{
        address p = L->First;
        address prev = Nil;

        while(p != Nil){
            if(p->info == X){
                address temp;
                if(prev == Nil){
                    L->First = p->next;
                    temp = p;
                    p = p->next;
                    free(temp);

                }else{
                    prev->next = p->next;
                    temp = p;
                    p = p->next;
                    free(temp);
                }

            }else{
                prev = p;
                p = p->next;
            }
        }

    }
    return;
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P){
    if(L->First->next == Nil){
        address *temp = L->First;
        Dealokasi(temp);
        CreateEmpty(L);
    }else{
        address p = Nil;
        address loc = L->First;

        while(loc->next != Nil){
            p = loc;
            loc = loc->next;
        }

        *P = loc;
        p->next = Nil;
    }
    return;
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec){
    address p = L->First;

    while(p->next != Nil && p != Prec){
        p = p->next;
    }
    p = p->next;
    *Pdel = p;
    
    Prec->next = p->next;

}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L){
    if(IsEmpty(L)){
        printf("[]\n");
        return;
    }

    printf("[");
    address p = L.First;

    while(p != Nil){
        printf("%d", p->info);

        if(p->next != Nil){
            printf(",");
        }
        p = p->next;
    }
    printf("]\n");
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L){
    if(IsEmpty(L)) return 0;

    int count = 0;
    address p = L.First;
    while(p != Nil){
        count++;
        p = p->next;
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L){
    address p = L.First;
    infotype max = p->info;

    while(p!=Nil){
        if(p->info > max){
            max = p->info;
        }
        p = p->next;
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
address AdrMax (List L){
    infotype maximum = Max(L);

    address p = L.First;
    while(p != Nil){
        if(p->info == maximum){
            return p;
        }
        p = p->next;
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
infotype Min (List L){
    address p = L.First;
    infotype min = p->info;

    while(p!=Nil){
        if(p->info < min){
            min = p->info;
        }
        p = p->next;
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
address AdrMin (List L){
    infotype minimum = Min(L);

    address p = L.First;
    while(p != Nil){
        if(p->info == minimum){
            return p;
        }
        p = p->next;
    }
    return p;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float Average (List L){
    float total = 0;
    address p = L.First;
    float count = 0;

    while(p != Nil){
        total += p->info;
        count++;
        p = p->next;
    }

    float result = total/count;
    return result;

    
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void InversList (List *L){
    address prev = Nil;
    address current = L->First;
    address next;

    while(current != Nil){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    L->First = prev;

}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void Konkat1 (List *L1, List *L2, List *L3){
    CreateEmpty(L3);
    address p = L1->First;
    while(p!=Nil){
        InsVLast(L3,p->info);
        // address temp = p;
        p = p->next;
        // free(temp);
    }

     p = L2->First;
    while(p!=Nil){
        InsVLast(L3,p->info);
        // address temp = p;
        p = p->next;
        // free(temp);
    }

    CreateEmpty(L1);
    CreateEmpty(L2);
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */