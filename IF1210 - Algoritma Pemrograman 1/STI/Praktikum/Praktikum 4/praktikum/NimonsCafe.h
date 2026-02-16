#ifndef NIMONSCAFE_H
#define NIMONSCAFE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Enum untuk tipe gula */
typedef enum{
    LESS_SUGAR,
    NORMAL_SUGAR,
    EXTRA_SUGAR
} TipeGula;

typedef enum{
    LESS_ICE, NORMAL_ICE, NO_ICE
}TipeEs;

typedef struct{
    char namaMinuman[50];
    char ukuran;
    TipeEs tipeEs;
    TipeGula tipeGula;

}PesananMinuman;


/* Constructor */

/**
 * Membuat pesanan minuman berdasarkan:
 * - nama minuman
 * - ukuran ('S', 'M', 'L')
 * - tipe gula (LESS_SUGAR, NORMAL_SUGAR, EXTRA_SUGAR)
 * - tipe es (LESS_ICE, NORMAL_ICE, NO_ICE)
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(nimons.pekerjaan, pekerjaan);
 */
PesananMinuman BuatPesanan(char *nama, char ukuran, TipeGula tGula, TipeEs tEs);

/* Getter & Setter */

/**
 * Return nama minuman
 */
char *getNamaMinuman(PesananMinuman *p);

/**
 * Mengubah nama minuman
 */
void setNamaMinuman(PesananMinuman *p, char *nama);

/**
 * Return ukuran minuman
 */
char getUkuran(PesananMinuman p);

/**
 * Mengubah ukuran pesanan menjadi ukuran baru
 * Contoh: 
 * Mengubah ukuran minuman M menjadi S
 */
void setUkuran(PesananMinuman *p, char ukuran);

/**
 * Return Tipe Gula minuman
 */
TipeGula getTipeGula(PesananMinuman p);
/**
 * Mengubah Tipe Gula minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeGula(PesananMinuman *p, TipeGula tGula);

/**
 * Return Tipe Es dari minuman
 */
TipeEs getTipeEs(PesananMinuman p);

/**
 * Mengubah Tipe Es dari minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeEs(PesananMinuman *p, TipeEs tEs);

/* Display */

/**
 * Menampilkan pesanan dalam format:
 * <namaMinuman> - <ukuran> - <tipeGula>, <tipeEs>
 * Contoh Output:
 * "Cappuccino - M - normal sugar, less ice"
 * 
 * PASTIKAN ADA ENDLINE DI AKHIR OUTPUT!
 */
void TulisPesanan(PesananMinuman p);

/* Utility */

/**
 * Menghitung total kalori berdasarkan:
 * - Ukuran:
 *     S = 100 kalori
 *     M = 150 kalori
 *     L = 200 kalori
 * - Gula:
 *     LESS_SUGAR = +10 kalori
 *     NORMAL_SUGAR = +20 kalori
 *     EXTRA_SUGAR = +40 kalori
 * 
 * Return: nilai kalori dalam bilangan bulat
 */
int TotalKalori(PesananMinuman p);

/**
 * Menghitung volume bersih (tanpa es) berdasarkan:
 * - Ukuran:
 *     S = 240 ml
 *     M = 360 ml
 *     L = 480 ml
 * - Es:
 *     volume es pada NORMAL_ICE = 25% dari volume ukuran
 *     volume es pada LESS_ICE = 10% dari volume ukuran
 *     volume es pada NO_ICE = 0% dari volume ukuran
 *
 * Return: volume bersih dalam bilangan bulat
 */
int VolumeBersih(PesananMinuman p);

#endif