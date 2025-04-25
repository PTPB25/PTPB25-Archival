/* File: PasienNimons.h */
/* Deskripsi: ADT kompleks untuk data pasien Nimons yang mencakup data vital, lokasi, dan identitas */

#ifndef OPERASI_H
#define OPERASI_H

#include <stdbool.h>

/* ADT Vital: Menyimpan data vital pasien */
typedef struct {
    int tekananDarah;        // dalam mmHg
    int detakJantung;        // dalam bpm
    float saturasiOksigen;   // dalam persen (0.0 - 100.0)
} Vital;

/* ADT Lokasi: Menyimpan koordinat pasien dalam ruangan RS */
typedef struct {
    int x;  // Kolom (misal: 0 = IGD, 1 = ICU, dst)
    int y;  // Baris (misal: 0 = lantai 1, dst)
} Lokasi;

/* ADT Pasien */
typedef struct {
    char nama[50];
    Vital v;
    Lokasi l;
} Pasien;

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi);
Lokasi MakeLokasi(int x, int y);
Pasien MakePasien(char nama[], Vital v, Lokasi l);

/* --- Aksesor --- */
int GetTekanan(Vital v);
int GetDetak(Vital v);
float GetSaturasi(Vital v);
int GetX(Lokasi l);
int GetY(Lokasi l);
Vital GetVital(Pasien p);
Lokasi GetLokasi(Pasien p);

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan);
void SetDetak(Vital *v, int detak);
void SetSaturasi(Vital *v, float saturasi);
void SetX(Lokasi *l, int x);
void SetY(Lokasi *l, int y);
void SetVital(Pasien *p, Vital v);
void SetLokasi(Pasien *p, Lokasi l);

/* --- Operasi Vital --- */
bool IsSehat(Vital v);
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v);
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b);
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy);
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v);
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l);
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p);
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/

#endif