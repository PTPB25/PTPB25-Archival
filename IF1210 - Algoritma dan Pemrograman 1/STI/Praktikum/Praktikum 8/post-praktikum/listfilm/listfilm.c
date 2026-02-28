#include <stdio.h>
#include "listfilm.h"

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
void InsertAfter (List *L, address P, address Prec){
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
        address temp = L->First;
        Dealokasi(&temp);
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
        address temp = L->First;
        Dealokasi(&temp);
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

/****************** Fungsi Tambahan ******************/
void RemoveGenre(List *L, infotype X){
    if(IsEmpty(*L)) {
        printf("Tidak ada film yang memiliki genre dengan ID: %d\n",X);
        return;
    }
    
    // printf("angka awal %d\n", L->First->info);
    int count = 0;
    address current = L->First;
    address prev = Nil;
    

    while(current != Nil){
        // printf("angka sekarang %d\n", current->info);
            if (current == L->First && current->info == X){
                // printf("masuk cek head\n");
                L->First = current->next;
                address temp = current;
                current = temp->next;
                prev = current;
                free(temp);
                count++;
            }
            else if(current->info == X){
                // printf("angka %d\n", current->info);
                address temp = current;
                current = temp->next;
                prev->next = current;
                free(temp);
                count++;
            }else{
                prev = current;
                current = current->next;

            }
        }
        

    
    if(count == 0){
        printf("Tidak ada film yang memiliki genre dengan ID: %d\n",X);
    }else{
        printf("Berhasil menghapus %d film\n",count);
    }
    if(L->First == NULL) CreateEmpty(L);

}
/* I.S.  : List L terdefinisi, mungkin kosong. 
           X merupakan ID genre (tipe integer) yang akan dihapus. */
/* F.S.  : Semua film dalam list yang memiliki genre dengan ID = X telah dihapus. 
           Setiap elemen yang dihapus akan didealokasi.
           Mencetak banyaknya film yang terhapus dengan format
           "Berhasil menghapus <banyaknya> film",
           Jika tidak ada film yang dihapus maka tampilkan
           "Tidak ada film yang memiliki genre dengan ID: <X>"
           Setiap output diakhiri endline */
/* Proses: Melakukan traversal terhadap list, menghapus node yang memiliki genre = X, 
           serta mencetak total film yang berhasil dihapus. */
