#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur untuk setiap pasangan key-value dalam Map
typedef struct {
    int key;     // Key (integer)
    char *value; // Nilai (string)
} MapEntry;

// Definisi struktur untuk ADT Map
typedef struct {
    MapEntry *entries; // Array dinamis dari MapEntry
    int capacity;      // Kapasitas maksimum array
    int size;          // Jumlah elemen yang saat ini ada di Map
} Map;

/**
 * @brief Membuat dan menginisialisasi Map baru.
 *
 * @param capacity Kapasitas maksimum Map. Asumsikan bahwa nilai capacity selalu
 * > 0.
 * @return Pointer ke objek Map yang baru dibuat, atau NULL jika alokasi gagal
 * atau kapasitas tidak valid.
 */
Map *create_map(int capacity);

/**
 * @brief Menyisipkan pasangan key-value baru ke dalam Map, atau memperbarui
 * value jika key sudah ada.
 * Keterangan:
 * 1. String yang dijadikan value harus dialokasikan ulang agar kepemilikan
 * string tersebut berpindah ke map.
 * 2. Key harus terurut di dalam map entries
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang akan disisipkan atau diperbarui.
 * @param value Nilai yang akan diasosiasikan dengan kunci.
 * @return true jika berhasil (penyisipan atau pembaruan), false jika Map penuh
 * atau input tidak valid.
 */
bool map_insert(Map *map, int key, const char *value);

/**
 * @brief Mengambil value yang terikat dengan key tertentu.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari key yang sesuai
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang nilainya akan diambil.
 * @return nilai jika kunci ditemukan, atau NULL jika kunci
 * tidak ditemukan atau input tidak valid.
 */
char *map_get(const Map *map, int key);

/**
 * @brief Menghapus pasangan key-value dari Map berdasarkan key.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari entry yang akan dihapus
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci elemen yang akan dihapus.
 * @return true jika berhasil dihapus, false jika kunci tidak ditemukan atau
 * input tidak valid.
 */
bool map_delete(Map *map, int key);

/**
 * @brief Mendapatkan jumlah elemen (pasangan key-value) dalam Map.
 *
 * @param map Pointer ke objek Map.
 * @return Jumlah elemen dalam Map .
 */
int map_size(const Map *map);

/**
 * @brief Memeriksa apakah kunci tertentu ada di dalam Map.
 *
 * Keterangan:
 * Gunakan binary search untuk mencari key yang sesuai
 *
 * @param map Pointer ke objek Map.
 * @param key Kunci yang akan diperiksa keberadaannya.
 * @return true jika kunci ada, false jika kunci tidak ada.
 */
bool map_contains_key(const Map *map, int key);

#endif // MAP_H