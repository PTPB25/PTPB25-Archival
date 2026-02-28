#ifndef _NIMONS_BALAP_H_
#define _NIMONS_BALAP_H_

// Nama File: NimonsBalap.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dimensi {
    int panjang;
    int lebar;
    int tinggi;
} dimensi;

typedef struct Kendaraan {
    char kode[4];
    int jumlahKursi;
    int jumlahRoda;
    int kecepatan;
    dimensi dim;
    int berat;
    int hargaJual;
} kendaraan;

/* Getter & Setter */
char *getKode(kendaraan k);
void setKode(kendaraan *k, char *kode);

int getJumlahKursi(kendaraan k);
void setJumlahKursi(kendaraan *k, int jumlahKursi);

int getJumlahRoda(kendaraan k);
void setJumlahRoda(kendaraan *k, int jumlahRoda);

int getKecepatan(kendaraan k);
void setKecepatan(kendaraan *k, int kecepatan);

int getPanjang(kendaraan k);
void setPanjang(kendaraan *k, int panjang);

int getLebar(kendaraan k);
void setLebar(kendaraan *k, int lebar);

int getTinggi(kendaraan k);
void setTinggi(kendaraan *k, int tinggi);

int getBerat(kendaraan k);
void setBerat(kendaraan *k, int berat);

int getHargaJual(kendaraan k);
void setHargaJual(kendaraan *k, int hargaJual);

/* Constructor */

/**
 * Buat kendaraan dengan parameter:
 * - kode
 * - jumlahKursi
 * - jumlahRoda
 * - kecepatan
 * - dimensi (panjang, lebar, tinggi)
 * - berat
 * - harga
 */
kendaraan buatKendaraan(char *kode, int jumlahKursi, int jumlahRoda, int kecepatan, dimensi d, int berat, int hargaJual);

/**
 * Kendaraan default
 * - kode = "XXX"
 * - jumlahKursi = 4
 * - jumlahRoda = 4
 * - kecepatan = 10
 * - dim = 10x10x10
 * - berat = 100
 * - hargaJual = 100000
 *
 * Notes: Anda harus menggunakan fungsi buatKendaraan untuk membuat kendaraan
 */
void buatKendaraanDefault(kendaraan *k);

/**
 * Lakukan input detail kendaraan dari user dengan format:
 * <kode> <jumlahKursi> <jumlahRoda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <hargaJual>
 * Contoh: "XXX 4 4 10 10 10 10 1000 100000"
 *
 * Notes: Anda harus menggunakan fungsi buatKendaraan untuk membuat kendaraan
 */
void buatKendaraanInput(kendaraan *k);

/* Methods */

/**
 * Print detail kendaraan dengan format:
 * <kode> <jumlahKursi> <jumlahRoda> <kecepatan> <panjang> <lebar> <tinggi> <berat> <hargaJual>
 * Contoh: "XXX 4 4 10 10 10 10 1000 100000"
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printDetailKendaraan(kendaraan k);

/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * jumlah roda <= 2 -> NimoRide
 * jumlah roda > 2 && jumlah roda <= 4 -> NimoCar
 * jumlah roda > 4 && jumlah roda <= 6 -> NimoTruck
 * jumlah roda > 6 -> NimoTanker
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanRoda(kendaraan k);
/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * kecepatan <= 10 -> NimoSlow
 * kecepatan > 10 && kecepatan <= 20 -> NimoFast
 * kecepatan > 20 && kecepatan <= 30 -> NimoSuperFast
 * kecepatan > 30 -> NimoSpeedy
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanKecepatan(kendaraan k);
/**
 * Print jenis kendaraan berdasarkan kriteria berikut:
 * berat <= 100 -> NimoLight
 * berat > 100 && berat <= 200 -> NimoMedium
 * berat > 200 && berat <= 300 -> NimoHeavy
 * berat > 300 -> NimoSuperHeavy
 * 
 * Notes: Anda harus menggunakan getter untuk mendapatkan nilai dari kendaraan
 */
void printJenisKendaraanBerdasarkanBerat(kendaraan k);

/**
 * Hitung harga kendaraan berdasarkan kriteria berikut:
 * harga 1 buah roda = 1000
 * harga 1 buah kursi = 10000
 * harga 1 cm panjang = 100
 * harga 1 cm lebar = 100
 * harga 1 cm tinggi = 100
 * harga 1 kg berat = 100
 *
 * apabila harga kendaraan yang dihitung lebih dari harga jual kendaraan,
 * maka tampilkan pesan "Nimons Rugi! Harga rakit mobil <kode> lebih mahal dari harga jual"
 *
 * apabila harga kendaraan yang dihitung kurang dari harga jual kendaraan,
 * maka tampilkan pesan "Nimons Kaya hehe! Harga rakit mobil <kode> lebih murah dari harga jual"
 *
 * apabila harga kendaraan yang dihitung sama dengan harga jual kendaraan,
 * maka tampilkan pesan "Nimons Pas! Harga rakit mobil <kode> sama dengan harga jual"
 */
void jualKendaraan(kendaraan *k);

/**
 * Faktor penentu kemenangan dalam balap ini adalah:
 * - Kecepatan memiliki bobot 10
 * - Berat memiliki bobot -2
 * - Lebar memiliki bobot -1
 *
 * Tampilkan pesan "Nimons Balap! Kendaraan <kode> menang! dengan skor <skor>"
 *
 * Apabila kedua kendaraan memiliki skor yang sama,
 * tampilkan pesan "Nimons Balap! Kedua kendaraan <kode1> dan <kode2> seri! dengan skor <skor>"
 *
 * Notes: Skor dihitung dengan menjumlahkan faktor penentu kemenangan * bobot nya
 * contoh:
 * - Kecepatan = 20, bobot = 10 -> 20 * 10 = 200
 * - Berat = 1000, bobot = -2 -> 100 * -2 = -200
 * - Lebar = 10, bobot = -1 -> 10 * -1 = -10
 *
 * Skor = 200 - 200 - 10 = -10
 */
void pBalap(kendaraan *k1, kendaraan *k2);

#endif