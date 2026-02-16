#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdbool.h>
#include <stdio.h>

// Definisi struct untuk list statik
typedef struct {
    int *data;     // Array untuk menyimpan elemen list
    int ukuran;    // Jumlah elemen saat ini dalam list
    int kapasitas; // Kapasitas maksimum list
} ListStatik;

/**
 * @brief Menginisialisasi list statik.
 *
 * Fungsi ini mempersiapkan struct ListStatik untuk digunakan dengan mengatur
 * ukuran menjadi 0 dan kapasitas sesuai dengan capacity.
 *
 * @param list Pointer ke struct ListStatik yang akan diinisialisasi.
 */
void inisialisasiList(ListStatik *list, int capacity);

/**
 * @brief Menambahkan sebuah nilai ke akhir list statik.
 *
 * Fungsi ini menambahkan elemen baru ke posisi terakhir yang tersedia dalam
 * list. Sebelum menambahkan, fungsi ini akan memeriksa apakah list sudah penuh.
 *
 * @param list Pointer ke struct ListStatik.
 * @param nilai Nilai integer yang akan ditambahkan ke list.
 * @return true Jika elemen berhasil ditambahkan, false jika list sudah penuh.
 */
bool tambahElemen(ListStatik *list, int nilai);

/**
 * @brief Menghapus elemen terakhir dari list statik.
 *
 * Fungsi ini menghapus elemen yang berada di posisi paling akhir list.
 * Fungsi ini akan memeriksa apakah list kosong sebelum melakukan penghapusan.
 *
 * @param list Pointer ke struct ListStatik.
 * @return true Jika elemen berhasil dihapus, false jika list kosong.
 */
bool hapusElemenAkhir(ListStatik *list);

/**
 * @brief Menampilkan semua elemen yang ada di dalam list statik.
 *
 * Fungsi ini mencetak semua nilai elemen yang saat ini tersimpan dalam list.
 * Jika list kosong, fungsi ini akan menampilkan pesan bahwa list kosong.
 * Format output: "<elemen1><elemen2>...<elemenN>".
 * jika list kosong, tampilkan "List kosong".
 * Kedua output diakhiri dengan newline.
 *
 *
 * @param list Struct ListStatik yang akan ditampilkan.
 */
void tampilkanList(ListStatik list);

/**
 * @brief Mencari apakah suatu nilai terdapat di dalam list statik.
 *
 * Fungsi ini mencari kemunculan pertama dari nilai yang diberikan di dalam
 * list.
 *
 * @param list Struct ListStatik yang akan dicari.
 * @param nilai Nilai integer yang ingin dicari.
 * @return Indeks pertama tempat nilai ditemukan dalam list (dimulai dari 0).
 * Jika nilai tidak ditemukan, fungsi ini mengembalikan -1.
 */
int cariElemen(ListStatik list, int nilai);

/**
 * @brief Mengubah nilai elemen pada indeks tertentu dalam list statik.
 *
 * Fungsi ini mengganti nilai elemen yang berada pada indeks yang diberikan
 * dengan nilai yang baru. Fungsi ini akan memeriksa apakah indeks yang
 * diberikan valid.
 *
 * @param list Pointer ke struct ListStatik.
 * @param indeks Indeks dari elemen yang ingin diubah (dimulai dari 0).
 * @param nilaiBaru Nilai integer baru yang akan disimpan pada indeks tersebut.
 * @return true Jika perubahan berhasil (indeks valid), false jika indeks tidak
 * valid.
 */
bool ubahElemen(ListStatik *list, int indeks, int nilaiBaru);

#endif // LIST_STATIK_H