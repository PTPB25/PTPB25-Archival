
#include "operasi.h"
#include <string.h>
#include <stdio.h>

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    return (Vital){tekanan, detak, saturasi};
}
Lokasi MakeLokasi(int x, int y){
    return (Lokasi){x, y};
}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien p;
    p.v = v;
    p.l = l;
    strcpy(p.nama, nama);
    return p;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}
int GetDetak(Vital v){
    return v.detakJantung;
}
float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah = tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung = detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen = saturasi;
}
void SetX(Lokasi *l, int x){
    l->x = x;
}
void SetY(Lokasi *l, int y){
    l->y = y;
}
void SetVital(Pasien *p, Vital v){
    p->v = v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l = l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v){
    int tekanan = GetTekanan(v), detak = GetDetak(v);
    float sat = GetSaturasi(v);
    return (90 <= tekanan && tekanan <= 140 && 60 <= detak && detak <= 100 && sat >= 95);
}
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v){
    SetTekanan(v, 120);
    SetDetak(v, 80);
    SetSaturasi(v, 98);
}
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b){
    float vitalA = GetDetak(a) + GetTekanan(a) + GetSaturasi(a);
    float vitalB =  GetDetak(b) + GetTekanan(b) + GetSaturasi(b);
    return (vitalA < vitalB ? -1 : (vitalA > vitalB ? 1 : 0));
}
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy){
    l->x += dx;
    l->y += dy;
}
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v){
    printf("Tekanan: %d mmHg, Detak: %d bpm, Saturasi: %.2f%%\n", GetTekanan(v), GetDetak(v), GetSaturasi(v));
}
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l){
    printf("Lokasi: (%d, %d)\n", GetX(l), GetY(l));
}
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p){
    printf("Nama: %s\n", p.nama);   /* Asprak crime part 3 : gak dikasih tau harus pake 'Nama: ' */
    PrintVital(GetVital(p));
    PrintLokasi(GetLokasi(p));
}
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/
