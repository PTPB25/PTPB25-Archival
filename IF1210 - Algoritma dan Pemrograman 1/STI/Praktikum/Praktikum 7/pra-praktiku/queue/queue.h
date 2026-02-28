#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define SENTINEL -1

struct Queue {
    int items[MAX_SIZE]; // Array untuk menyimpan elemen integer
    int count;           // Jumlah elemen yang ada di array saat ini
};

/*
 * Fungsi untuk menginisialisasi queue.
 * Mengatur count ke 0.
 * Parameter:
 * - q: Pointer ke struct Queue yang akan diinisialisasi.
 */
void initQueue(struct Queue *q);

/*
 * Fungsi untuk mengecek apakah queue kosong.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - true jika queue kosong (count == 0), false jika tidak.
 */
bool isEmpty(struct Queue *q);

/*
 * Fungsi untuk mengecek apakah queue penuh.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - true jika queue penuh (count == MAX_SIZE - 1), false jika tidak.
 */
bool isFull(struct Queue *q);

/*
 * Fungsi untuk menambahkan elemen ke belakang (enqueue) queue.
 * Prekondisi: Queue belum penuh. Periksa isFull()
 * sebelum memanggil fungsi ini untuk menghindari overflow. Parameter:
 * - q: Pointer ke struct Queue.
 * - value: Nilai integer yang akan ditambahkan.
 * Postkondisi: Elemen ditambahkan ke queue jika tidak penuh.
 * Catatan: Jika queue kosong sebelum penambahan keluarkan pesan "Queue penuh!".
 */
void enqueue(struct Queue *q, int value);

/*
 * Fungsi untuk mengambil elemen dari depan (dequeue) queue.
 * Jika queue kosong, fungsi ini akan mencetak pesan error
 * dan mengembalikan nilai SENTINEL. Karena bukan circular queue, maka array
 * perlu di geser ke depan untuk mengisi ruang yang kosong setelah dequeue
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Nilai elemen integer yang diambil dari depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int dequeue(struct Queue *q);

/*
 * Fungsi untuk melihat elemen di depan queue tanpa menghapusnya (peek).
 * Prekondisi: Queue tidak kosong. Periksa isEmpty()
 * sebelum memanggil fungsi ini.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Nilai elemen integer yang berada di depan queue.
 * - Mengembalikan nilai SENTINEL jika queue kosong dan keluarkan pesan "Queue
 * kosong!".
 */
int front(struct Queue *q);

/*
 * Fungsi untuk mendapatkan jumlah elemen saat ini dalam queue.
 * Parameter:
 * - q: Pointer ke struct Queue.
 * Return:
 * - Jumlah elemen integer dalam queue saat ini (nilai count).
 */
int size(struct Queue *q);

#endif // QUEUE_H