#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * @brief Membuat node baru.
 *
 * @param data Nilai integer yang akan disimpan dalam node baru.
 * @return Node* Pointer ke node yang baru dibuat.
 * NULL jika alokasi memori gagal.
 */
Node *createNode(int data);

/**
 * @brief Mengecek apakah circular linked list kosong.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @return int 1 jika list kosong, 0 jika tidak.
 */
int isEmpty(Node *last);

/**
 * @brief Menambahkan node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika list awalnya kosong atau saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtBeginning(Node **last, int data);

/**
 * @brief Menambahkan node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi saat node baru ditambahkan.
 * @param data Nilai integer yang akan ditambahkan.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAtEnd(Node **last, int data);

/**
 * @brief Menambahkan node setelah node dengan nilai tertentu.
 * Jika ada beberapa node dengan nilai 'searchValue', node baru akan
 * dimasukkan setelah kemunculan pertama.
 * Jika 'searchValue' tidak ditemukan, node tidak ditambahkan.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai data dari node yang dicari untuk penyisipan
 * setelahnya.
 * @param data Nilai integer yang akan ditambahkan pada node baru.
 * @return true jika penambahan berhasil, false jika penambahan node gagal.
 */
bool insertAfter(Node **last, int searchValue, int data);

/**
 * @brief Menghapus node di awal circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi.
 */
void deleteFromBeginning(Node **last);

/**
 * @brief Menghapus node di akhir circular linked list.
 *
 * @param last Pointer ke pointer node terakhir dalam list
 *
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list kosong setelah penghapusan.
 *
 * Keterangan:
 */
void deleteFromEnd(Node **last);

/**
 * @brief Menghapus node dengan nilai tertentu dari circular linked list.
 * Jika ada beberapa node dengan nilai 'dataToDelete', hanya kemunculan
 * pertama yang akan dihapus.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan dimodifikasi jika node yang dihapus adalah node terakhir atau
 * satu-satunya node.
 * @param dataToDelete Nilai integer dari node yang akan dihapus.
 * @return Node* Pointer ke node terakhir setelah penghapusan.
 * NULL jika list menjadi kosong atau jika dataToDelete tidak ditemukan.
 */
void deleteNodeWithValue(Node **last, int dataToDelete);

/**
 * @brief Mencari sebuah nilai dalam circular linked list.
 *
 * @param last Pointer ke node terakhir dalam list.
 * @param searchValue Nilai integer yang akan dicari.
 * @return Node* Pointer ke node yang mengandung searchValue jika ditemukan.
 * NULL jika searchValue tidak ditemukan dalam list atau list kosong.
 */
Node *searchNode(Node *last, int searchValue);

/**
 * @brief Menampilkan semua elemen dalam circular linked list.
 * Dimulai dari node setelah node 'last' (yang secara efektif adalah awal list).
 *
 * @param last Pointer ke node terakhir dalam list.
 *
 * Keterangan:
 * 1. Jika list kosong maka keluarkan "KOSONG"
 * 2. Contoh keluaran: 1 -> 2 -> 3
 * 3. Akhiri keluaran dengan newline
 */
void displayList(Node *last);

/**
 * @brief Menghapus semua node dalam circular linked list dan membebaskan
 * memorinya.
 *
 * @param last Pointer ke pointer node terakhir dalam list.
 * Akan diatur menjadi NULL setelah semua node dihapus.
 */
void deleteAllNodes(Node **last);

#endif  