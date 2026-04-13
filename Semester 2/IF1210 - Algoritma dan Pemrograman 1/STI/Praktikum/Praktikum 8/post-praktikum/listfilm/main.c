#include "listfilm.h"
#include <stdio.h>
int main() {
    List L;
    CreateEmpty(&L);
    // Top 7 Film Terbaik
    infotype film1 = 1;
    infotype film2 = 2;
    infotype film3 = 3;
    infotype film4 = 2;
    infotype film5 = 3;
    infotype film6 = 2;
    infotype film7 = 4;

    // Tambahkan film ke list
    InsVLast(&L, film1);
    InsVLast(&L, film2);
    InsVLast(&L, film3);
    InsVLast(&L, film4);
    InsVLast(&L, film5);
    InsVLast(&L, film6);
    InsVLast(&L, film7);

    printf("=== Daftar Film Awal ===\n");
    PrintInfo(L);

    printf("\n=== Hapus Semua Genre: 1 (Awal List) ===\n");
    RemoveGenre(&L, 1);
    PrintInfo(L);

    printf("\n=== Hapus Semua Genre: 4 (Akhir List) ===\n");
    RemoveGenre(&L, 4);
    PrintInfo(L);

    printf("\n=== Hapus Semua Genre: 3 ===\n");
    RemoveGenre(&L, 3);
    PrintInfo(L);

    printf("\n=== Hapus Semua Genre: 2 ===\n");
    RemoveGenre(&L, 2);
    PrintInfo(L);

    printf("\n=== Hapus Genre Tidak Ada (5) ===\n");
    RemoveGenre(&L, 5);
    PrintInfo(L);
    return 0;
}