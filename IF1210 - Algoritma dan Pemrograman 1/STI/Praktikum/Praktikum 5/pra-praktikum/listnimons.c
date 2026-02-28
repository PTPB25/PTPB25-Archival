/* MODUL LIST NIMONS STATIK */
/* Berisi definisi dan semua primitif pemrosesan list statik untuk menyimpan data Nimons */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#include "Boolean.h"

/*  Kamus Umum */
#define NIMONS_CAPACITY 100
#define IDX_MIN 0
#define IDX_UNDEF -1

/* Definisi elemen dan koleksi objek */
typedef struct
{
    char name[21]; // nama Nimons, maksimal 20 karakter
    int age;       // umur Nimons
    int height;    // tinggi badan dalam cm
} Nimons;

typedef struct
{
    Nimons contents[NIMONS_CAPACITY];
} ListNimons;

/* Definisi Nimons kosong: name adalah string kosong ("") atau age = -1 */

/* ********** SELEKTOR ********** */
#define ELMT_NIMONS(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
void CreateListNimons(ListNimons *l){
    for(int i = 0; i<NIMONS_CAPACITY; i++){
        l->contents[i].name[0] = '\0';
        l->contents[i].age = -1;
        l->contents[i].height = 0;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk ListNimons l kosong dengan semua elemen memiliki name kosong dan age = -1 */

/* ********** SELEKTOR TAMBAHAN ********** */
int listNimonsLength(ListNimons l){
    int length = 0;
    for(int i = 0; i<NIMONS_CAPACITY; i++){
        if(l.contents[i].age == -1){
            return length;
        }
        length++;
    }
}
/* Mengirimkan banyaknya elemen efektif ListNimons */
/* Mengirimkan nol jika List kosong */

boolean isIdxValidNimons(ListNimons l, int i){
    return (i >= 0) && (i < NIMONS_CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid untuk kapasitas list */

boolean isIdxEffNimons(ListNimons l, int i){
    int neff = listNimonsLength(l);
    return (i>=0) && (i<neff);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi dalam list (0..length-1) */

boolean isNimonsEmpty(ListNimons l){
    return listNimonsLength(l) == 0;
}
/* Mengirimkan true jika ListNimons kosong */

boolean isNimonsFull(ListNimons l){
    return listNimonsLength(l) == NIMONS_CAPACITY;
}
/* Mengirimkan true jika ListNimons penuh */

/* ********** BACA dan TULIS ********** */
void readNimonsList(ListNimons *l){
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%s %d %d", l->contents[i].name, &l->contents[i].age, &l->contents[i].height);
    }
}
/* I.S. l sembarang */
/* F.S. ListNimons l berisi n data Nimons hasil pembacaan dari user */
/* Format: nama umur tinggi, misalnya: Bob 8 100 */

void printNimonsList(ListNimons l){
    int neff = listNimonsLength(l);
    printf("[");
    for(int i = 0; i<neff; i++){
        printf("%s-%d-%d");
        if(i < neff-1){
            printf(", ");
        }
    }
    printf("]\n");
    
}
/* Proses : Menuliskan isi ListNimons dalam format:
   [name1-age1-height1, name2-age2-height2, ..., nameN-ageN-heightN] */

/* ********** MENAMBAH dan MENGHAPUS ********** */
void insertNimonsLast(ListNimons *l, Nimons m){
    int len = listNimonsLength(*l);
    ELMT_NIMONS(*l, len) = m;
}
/* Menambahkan Nimons m sebagai elemen terakhir */

void deleteNimonsLast(ListNimons *l, Nimons *m){
    int len = listNimonsLength(*l);
    *m = ELMT_NIMONS(*l,len-1);
    l->contents[len-1].age = -1;
    l->contents[len-1].name[0]= '\0';
    l->contents[len-1].height = 0;
}
/* Menghapus elemen terakhir list dan menyimpan ke *m */

/* ********** SEARCHING ********** */
int indexOfNimons(ListNimons l, char *name);
/* Mencari nama Nimons dalam list.
   Mengembalikan indeks pertama yang cocok, atau IDX_UNDEF jika tidak ditemukan */

/* ********** NILAI EKSTREM ********** */
void findTallestShortest(ListNimons l, Nimons *tallest, Nimons *shortest);
/* Menentukan Nimons dengan tinggi tertinggi dan terendah dari list */
