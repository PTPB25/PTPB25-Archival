/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l){
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */

/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

IdxType getLastIdx(ListDin l){
    return NEFF(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */


/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i){
    return IDX_MIN <= i && i < CAPACITY(l);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff(ListDin l, IdxType i){
    return IDX_MIN <= i && i < NEFF(l);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return !NEFF(l);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return NEFF(l) == CAPACITY(l);
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    IdxType n, i;

    scanf("%d", &n);
    while(n < 0 || n > CAPACITY(*l))scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
    NEFF(*l) = n;
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printList(ListDin l){
    IdxType i, n;

    printf("[");
    n = NEFF(l);
    for(i = 0; i < n; i++){
        printf("%d", ELMT(l, i));
        if(i < n-1)printf(",");
    }
    printf("]");
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    IdxType i, n;
    ListDin result;
    
    n = NEFF(l1);
    CreateListDin(&result, n);
    
    for(i = 0; i < n; i++){
        ELMT(result, i) = (plus ? ELMT(l1, i) + ELMT(l2, i) : ELMT(l1, i) - ELMT(l2, i));
    }
    NEFF(result) = n;
    return result;
}
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
    if(NEFF(l1) != NEFF(l2)) return 0;

    IdxType i, n;
    n = NEFF(l1);
    for(i = 0; i < n; i++) if(ELMT(l1, i) != ELMT(l2, i)) return 0;
    return 1;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */


/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
    IdxType i, n;

    n = NEFF(l);
    for(i = 0; i < n; i++) if(ELMT(l, i) == val) return i;
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */


/* ********** NILAI EKSTREM ********** */
void extremeValues(ListDin l, ElType *max, ElType *min){
    IdxType i, n;

    n = NEFF(l);
    *max = ELMT(l, 0);
    *min = ELMT(l, 0);
    for(i = 1; i < n; i++){
        if(*max < ELMT(l, i)) *max = ELMT(l, i);
        if(*min > ELMT(l, i)) *min = ELMT(l, i);
    }
}
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */


/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){ 
    IdxType i, n;
    CreateListDin(lOut, CAPACITY(lIn));

    n = NEFF(lIn);
    for(i = 0; i < n; i++){
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = n;
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

ElType sumList(ListDin l){
    ElType sum;
    IdxType i, n;

    n = NEFF(l);
    sum = 0;
    for(i = 0; i < n; i++){
        sum += ELMT(l, i);
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */


int countVal(ListDin l, ElType val){
    int cnt;
    IdxType i, n;

    n = NEFF(l);
    cnt = 0;
    for(i = 0; i < n; i++) if(ELMT(l, i) == val) cnt++;
    return cnt;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */


/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
    IdxType i, j, n;
    ElType temp;

    n = NEFF(*l);
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(asc ? ELMT(*l, j) > ELMT(*l, j+1) : ELMT(*l, j) < ELMT(*l, j+1)){
                temp = ELMT(*l, j);
                ELMT(*l, j) = ELMT(*l, j+1);
                ELMT(*l, j+1) = temp;
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)++;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, NEFF(*l)-1);
    NEFF(*l)--;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */


/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num){
    ListDin new;
    IdxType i, n;
    CreateListDin(&new, CAPACITY(*l) + num);

    n = NEFF(*l);
    for(i = 0; i < n; i++){
        ELMT(new, i) = ELMT(*l, i);
    }
    NEFF(new) = n;

    dealocateList(l);
    *l = new;
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    ListDin new;
    IdxType i, n;
    CreateListDin(&new, CAPACITY(*l) - num);

    n = NEFF(*l);
    for(i = 0; i < n; i++){
        ELMT(new, i) = ELMT(*l, i);
    }
    NEFF(new) = n;

    dealocateList(l);
    *l = new;
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressList(ListDin *l){
    shrinkList(l, CAPACITY(*l) - NEFF(*l));
}
/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */