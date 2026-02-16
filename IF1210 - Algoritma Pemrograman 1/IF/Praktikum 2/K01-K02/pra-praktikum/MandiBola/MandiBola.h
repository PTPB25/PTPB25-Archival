#ifndef MANDIBOLA_H
#define MANDIBOLA_H

#include <stdio.h>

// Program Pemesanan Tiket Mandi Bola

/**
----------------------------------------
Selamat datang di Wahana Mandi Bola!

Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.

Harga tiket:
- Anak-anak (usia 0-12 tahun): Rp 10000
- Dewasa (usia 13-64 tahun): Rp 20000
- Lansia (usia 65 tahun ke atas): Rp 15000

Jumlah anak: <jumlah_anak>
Jumlah dewasa: <jumlah_dewasa>
Jumlah lansia: <jumlah_lansia>
 * Note:
 * - Jumlah anak-anak, dewasa, dan lansia masing-masing tidak akan lebih dari 9
 * - Silakan berkreatifitas sendiri untuk mendapatkan variable yang dibutuhkan dari input
 */
void SelamatDatang(int input);

/**
 * Menghitung total biaya tiket berdasarkan jumlah pengunjung
 */
int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia);

/**
 * Tiket berhasil dibeli!
 * Rincian:
 * - Jumlah anak-anak: <jumlah_anak>
 * - Jumlah dewasa: <jumlah_dewasa>
 * - Jumlah lansia: <jumlah_lansia>
 * - Total biaya: <total_biaya>
 */
void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia);

// Program Treasure Hunting Nimons

/**
----------------------------------------
Selamat datang di Treasure Hunting Nimons!

Jumlah pergerakan Nimons di dalam kolam: <jumlah_pergerakan>
Jumlah lubang yang ada di kolam: <jumlah_lubang>
Jumlah harta karun yang ada di kolam: <jumlah_harta_karun>
Langkah ke-1
{jika input = 0}Nimons tidak bergerak
{jika input = 1}Nimons menemukan harta karun!
{jika input = 1}Nimons menutup lubang!
...
Langkah ke-<n>
{jika input > 0}Nimons bergerak sejauh <banyak_langkah> langkah
{jika input = 1}Nimons menemukan harta karun!
{jika input = 1}Nimons menutup lubang!

Total lubang yang ditutup: <jumlah_lubang_ditutup> dari <jumlah_lubang> lubang
Total harta karun yang ditemukan: <total_harta_karun>
Total harga harta karun yang ditemukan: <total_harta_karun * harga * 5>
Total langkah yang ditempuh: <total_langkah>
Total biaya ganti rugi Pak Gro: <harga * jumlah_lubang_ditutup>
Total keuntungan Nimons dan Pak Gro: <total_harga_harta_karun - total_biaya_ganti_rugi>
 * Notes:
 * - semua variable memiliki range nilai 0-9 kecuali harga
 * - Silakan berkreatifitas sendiri untuk mendapatkan variable yang dibutuhkan dari input
 * - Format input sebagai berikut
 *   <harga><tutup_lubang><temukan_harta><langkah>...<tutup_lubang><temukan_harta><langkah><jumlah_harta_karun><jumlah_lubang><jumlah_pergerakan>
 */
void HandleNimonsHunting(long input);

#endif