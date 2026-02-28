#ifndef PASSWORD_H
#define PASSWORD_H

#include <math.h>
#include <stdio.h>

/**
 * Fungsi untuk mendapatkan panjang angka
 *
 * Hint: gunakan log10
 *
 * kembalikan -1 jika angka == 0
 */
int length(int angka);

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 *
 * Contoh:
 * angka = 1234
 *
 * index = 2
 * return -> 2
 *
 * index = 1
 * return -> 3
 *
 * index = 0
 * return -> 4
 *
 * index = 4
 * return -> -1
 *
 * Hint: Gunakan operasi matematika power, module, dan div
 *
 * kembalikan -1 jika index > panjang atau index < 0
 */
int getDigit(int angka, int index);

/**
 * Fungsi untuk menghapus digit ke-i dari kanan (misal: hapus index ke 2 dari 1234 -> 124)
 *
 *
 * Hint: Gunakan operasi matematika power, module, dan div untuk mendapatkan angka sebelah kiri dan kanan index lalu gabungkan dengan menggunakan perkalian power of 10 dan penjumlahan
 *
 * kembalikan angka yang sama jika index > panjang atau index < 0
 */
int removeDigit(int angka, int index);

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka
 * 
 * Hint:
 * - gunakan loop untuk melakukan iterasi ke seluruh digit di angka
 * - gunakan digit yang dipilih (dalam loop diatas) sebagai new current
 *   - current = 1, digit = 2 -> new current = 12
 * - hilangkan digit yang dipilih (dalam loop diatas) sebagai new angka
 *   - angka = 1234, digit yang dipilih = 2 -> new angka = 134
 * - panggil kembali fungsi rekursif
 */
void cariKombinasi(int angka, int current, int panjangAwal);

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void findPassword(int angka);

#endif