#include <stdio.h>
#include <string.h>
#include "circular_queue.h"

int main() {
    Queue Q;
    CreateQueue(&Q);

    // Cek apakah queue kosong
    if (IsEmpty(Q)) {
        printf("Queue kosong\n");
    }

    // Enqueue beberapa tim
    Tim t1 = {"Tim Api Membara"};
    Tim t2 = {"Tim Hihang Hoheng"};
    Tim t3 = {"Tim Air Beku"};
    Tim t4 = {"Tim Pisang Panggang"};
    Tim t5 = {"Tim Es Batu"};

    printf("\nMelakukan enqueue...\n");
    enqueue(&Q, t1);
    enqueue(&Q, t2);
    enqueue(&Q, t3);
    enqueue(&Q, t4);
    enqueue(&Q, t5);

    printf("Isi queue setelah enqueue:\n");
    displayQueue(Q);

    // Cek apakah queue penuh
    if (IsFull(Q)) {
        printf("Queue penuh\n");
    }
    else {
        printf("Queue belum penuh\n");
    }

    // Cek panjang queue
    printf("Panjang antrean tim: %d antrean\n", Length(Q));

    // Peek elemen terdepan
    Tim depan = peek(Q);
    printf("Tim terdepan (peek): %s\n", depan.namaTim);

    // Dequeue dua kali
    printf("\nMelakukan dequeue...\n");
    Tim keluar1 = dequeue(&Q);
    printf("Tim yang dikeluarkan: %s\n", keluar1.namaTim);
    Tim keluar2 = dequeue(&Q);
    printf("Tim yang dikeluarkan: %s\n", keluar2.namaTim);

    printf("\nIsi queue setelah dequeue:\n");
    displayQueue(Q);

    // Menambahkan tim untuk menguji circularity
    Tim t6 = {"Tim Salju"};
    Tim t7 = {"Tim Lava"};
    enqueue(&Q, t6);
    enqueue(&Q, t7);

    printf("\nIsi queue setelah menambahkan 2 tim baru:\n");
    displayQueue(Q);

    // Habisin queue
    printf("\nMengosongkan queue...\n");
    while (!IsEmpty(Q)) {
        Tim keluar = dequeue(&Q);
        printf("Mengeluarkan: %s\n", keluar.namaTim);
    }

    // Final check
    printf("\nQueue setelah dikosongkan:\n");
    displayQueue(Q);

    if (IsEmpty(Q)) {
        printf("Queue sekarang kosong.\n");
    }

    return 0;
}