#include "queue.h"
#include <stdio.h>

int main() {
    struct Queue myQueue;

    printf("--- Memulai Pengujian Queue ---\n");

    printf("\n1. Inisialisasi queue...\n");
    initQueue(&myQueue);
    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    printf("\n2. Menambahkan elemen (enqueue)...\n");
    enqueue(&myQueue, 10);
    printf("Enqueue 10. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    enqueue(&myQueue, 20);
    printf("Enqueue 20. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    enqueue(&myQueue, 30);
    printf("Enqueue 30. Ukuran: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");

    printf("\n3. Mengambil elemen (dequeue)...\n");
    int item = dequeue(&myQueue);
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    item = dequeue(&myQueue);
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    item = dequeue(&myQueue);
    printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));

    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    printf("\n4. Mencoba dequeue dari queue kosong...\n");
    item = dequeue(&myQueue);
    printf("Hasil dequeue: %d\n", item);

    printf("\n5. Menambahkan elemen hingga penuh (MAX_SIZE = %d)...\n",
           MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        if (!isFull(&myQueue)) {
            enqueue(&myQueue, (i + 1) * 100);
            printf("Enqueue %d. Ukuran: %d\n", (i + 1) * 100, size(&myQueue));
        } else {
            printf("Gagal enqueue %d, queue penuh.\n", (i + 1) * 100);
        }
    }

    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));
    printf("Elemen depan: %d\n", front(&myQueue));

    printf("\n6. Mencoba enqueue ke queue penuh...\n");
    enqueue(&myQueue, 999);
    printf("Ukuran queue setelah mencoba enqueue ke penuh: %d\n",
           size(&myQueue));

    printf("\n7. Mengosongkan queue...\n");
    while (!isEmpty(&myQueue)) {
        item = dequeue(&myQueue);
        printf("Dequeue: %d. Ukuran: %d\n", item, size(&myQueue));
    }

    printf("Status: Queue kosong? %s\n", isEmpty(&myQueue) ? "Ya" : "Tidak");
    printf("Status: Queue penuh? %s\n", isFull(&myQueue) ? "Ya" : "Tidak");
    printf("Ukuran queue: %d\n", size(&myQueue));

    printf("\n8. Mencoba front dari queue kosong\n");
    item = front(&myQueue);
    printf("Hasil front: %d\n", item);

    printf("\n--- Pengujian Queue Selesai ---\n");

    return 0;
}