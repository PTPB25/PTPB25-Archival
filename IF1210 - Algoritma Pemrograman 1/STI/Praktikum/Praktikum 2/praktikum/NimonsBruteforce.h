#ifndef NIMONSBRUTEFORCE_H
#define NIMONSBRUTEFORCE_H

#include <math.h>
#include <stdio.h>

/**
 * Fungsi untuk mendapatkan panjang angka 
 * 
 * kembalikan -1 jika angka == 0
 */
int length(int angka);

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 *
 * kembalikan -1 jika index > panjang atau index < 0
 */
int getDigit(int angka, int index);

/**
 * Fungsi untuk menghapus digit ke-i dari kanan (misal: hapus index ke 2 dari 1234 -> 124)
 * 
 * kembalikan angka yang sama jika index > panjang atau index < 0
 */
int removeDigit(int angka, int index);

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka
 */
void cariKombinasi(int angka, int current, int panjangAwal);

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void NimonBruteforce(int angka);

#endif