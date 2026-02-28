#include <stdio.h>
#include "MegaNimons.h"
/* *** Type Data *** */
typedef int IdxType;

// /* Struktur MegaNimons */
// typedef struct {
//     int id;                         // ID eksperimen unik
//     char name[30];                  // Nama MegaNimons
//     float powerLevel;              // Power level maksimum MegaNimons
//     char mutationType[20];         // Tipe mutasi (contoh: "fly", "laser", dsb.)
//     boolean isStable;              // TRUE kalau stable, FALSE kalau unstable
// } MegaNimons;

// /* Struktur LabTrack */
// typedef struct {
//     MegaNimons contents[CAPACITY]; // Tempat penyimpanan data MegaNimons
//     int nEff;                      // Jumlah elemen efektif dalam list
// } LabTrack;

/**
 * Rentang indeks yang digunakan adalah [0 .. CAPACITY-1]
 * Jika L adalah LabTrack:
 *   - L.contents[i] mengakses MegaNimons ke-i
 *   - L.nEff menyatakan jumlah elemen yang valid
 * 
 * Definisi:
 *   - List kosong: L.nEff = 0
 *   - Elemen pertama: L.contents[0]
 *   - Elemen terakhir: L.contents[L.nEff - 1]
 */

/* ********** KONSTRUKTOR ********** */
/**
 * I.S. sembarang
 * F.S. Terbentuk list kosong dengan jumlah elemen efektif 0
 */
void createLabTrack(LabTrack *L){
    L->nEff = 0;
}

/* ********** SELEKTOR ********** */
/**
 * Mengembalikan banyaknya elemen efektif
 */
int length(LabTrack L){
    return L.nEff;
}

/**
 * Mengembalikan kapasitas maksimum list
 */
int maxCapacity(){
    return CAPACITY;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen pertama
 */
IdxType firstIdx(LabTrack L){
    return 0;
}

/**
 * Prekondisi: L tidak kosong
 * Mengembalikan indeks elemen terakhir
 */
IdxType lastIdx(LabTrack L){
    return L.nEff-1;
}

/**
 * Mengembalikan MegaNimons pada indeks ke-i
 * Prekondisi: i adalah indeks efektif yang valid
 */
MegaNimons getElmt(LabTrack L, IdxType i){
    return L.contents[i];
}

/* ********** SETTER ********** */
/**
 * Mengubah elemen pada indeks i menjadi nilai val
 */
void setElmt(LabTrack *L, IdxType i, MegaNimons val){
    L->contents[i] = val;
}

/**
 * Mengatur nilai jumlah elemen efektif menjadi N
 */
void setLength(LabTrack *L, int N){
    L->nEff = N;
}

/* ********** Validasi INDEKS ********** */
/**
 * Mengembalikan true jika indeks berada dalam rentang kapasitas [0..CAPACITY-1]
 */
boolean isIdxValid(IdxType i){
    if (i <= CAPACITY-1 && i >= 0){
        return TRUE;
    }
    return FALSE;
}

/**
 * Mengembalikan true jika indeks adalah indeks efektif [0..nEff-1]
 */
boolean isIdxEff(LabTrack L, IdxType i){
    if ( i<L.nEff && i>=0){
        return TRUE;
    }
    return FALSE;
}

/* ********** TEST KOSONG/PENUH ********** */
/**
 * Mengembalikan true jika list kosong
 */
boolean isEmpty(LabTrack L){
    if(L.nEff == 0){
        return TRUE;
    }
    return FALSE;
}

/**
 * Mengembalikan true jika list penuh
 */
boolean isFull(LabTrack L){
    if(L.nEff == CAPACITY){
        return TRUE;
    }
    return FALSE;
}

/* ********** Operasi Dasar ********** */
/**
 * Menyisipkan MegaNimons pada indeks tertentu
 * Semua elemen setelah indeks digeser ke kanan
 */
void insertAt(LabTrack *L, MegaNimons m, IdxType idx){
    if(L->nEff + 1 <= CAPACITY){
        for(int i = L->nEff -1 ; i > idx; i--){
            L->contents[i] = L->contents[i-1];
        }
        L->contents[idx] = m;
        L->nEff++;
    }
}

/**
 * Menambahkan MegaNimons ke posisi pertama dalam list
 * Semua elemen yang ada digeser ke kanan
 */
void insertFirst(LabTrack *L, MegaNimons m){
    if(L->nEff + 1 <= CAPACITY){
        for(int i = L->nEff -1 ; i > 0; i--){
            L->contents[i] = L->contents[i-1];
        }
        L->contents[0] = m;
        L->nEff++;
    }
}

/**
 * Menambahkan MegaNimons ke posisi terakhir dalam list
 */
void insertLast(LabTrack *L, MegaNimons m){
    if(L->nEff + 1 <= CAPACITY){
        L->contents[L->nEff] = m ;
        L->nEff++;
    }
}

/**
 * Menghapus MegaNimons pada indeks tertentu
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteAt(LabTrack *L, IdxType idx, MegaNimons *m){
    *m = L->contents[idx];
    for(int i = idx; i<L->nEff-1; i++){
        L->contents[i] = L->contents[i+1];
    }
    L->nEff--;

}

/**
 * Menghapus MegaNimons pada indeks pertama (0)
 * Semua elemen setelahnya digeser ke kiri
 * Elemen yang dihapus disimpan pada *m
 */
void deleteFirst(LabTrack *L, MegaNimons *m){
    deleteAt(L, 0, m);
}

/**
 * Menghapus MegaNimons pada indeks terakhir
 * Elemen terakhir disimpan pada *m
 */
void deleteLast(LabTrack *L, MegaNimons *m){
    *m = L->contents[L->nEff-1];
    L->nEff--;
}

/**
 * Mengembalikan indeks MegaNimons berdasarkan ID
 * Jika tidak ditemukan, mengembalikan IDX_UNDEF
 */
IdxType indexOf(LabTrack L, int id){
    IdxType index;
    for(int i = 0; i < L.nEff; i++){
        if(L.contents[i].id == id){
            index = i;
            return index;
        }
    }
    return IDX_UNDEF;
}

/* ********** Utilitas dan Output ********** */
/**
 * Menampilkan seluruh isi list MegaNimons
 * Format: [index]: ID=xxx NAME=xxx POWER=xxx.x MUT=xxx STABLE=Yes/No
 */
void printLabTrack(LabTrack L){
    for(int i = 0; i<L.nEff; i++){
        printf("[%d]: ID=%d NAME=%s POWER=%.1f MUT=%s ",i,L.contents[i].id,L.contents[i].name,L.contents[i].powerLevel,L.contents[i].mutationType);
        if(L.contents[i].isStable==TRUE){
            printf("STABLE=Yes\n");
        }else{
            printf("STABLE=No\n");
        }
    }
}

boolean isPowerEqual(MegaNimons m1, MegaNimons m2){
    if(m1.powerLevel == m2.powerLevel){
        return TRUE;
    }
    return FALSE;
}

boolean isMoreStable(MegaNimons m1, MegaNimons m2){
    if(m1.isStable > m2.isStable){
        return TRUE;
    }
    return FALSE;
}

MegaNimons resolveDuel(MegaNimons m1,MegaNimons m2){
    MegaNimons winner;
    if(isPowerEqual(m1,m2)){
        if(m1.isStable == m2.isStable){
            winner = (m1.id < m2.id) ? m1 : m2;
        }
        else{
            winner = (isMoreStable(m1,m2)) ? m1 : m2;
        }
    }
    else{
        winner = (m1.powerLevel > m2.powerLevel) ? m1 : m2;
    }
    return winner;
}

void duelOnce(MegaNimons m1,MegaNimons m2){
    MegaNimons winner = resolveDuel(m1,m2);
    printf("Duel: %s (%1.f) vs %s (%1.f)\nWinner: %s\n", m1.name, m1.powerLevel, m2.name, m2.powerLevel, winner.name);
}