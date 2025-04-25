#ifndef POINT_H
#define POINT_H

#include "boolean.h"  

/* Definisi type POINT */
typedef struct {
    float X;  /* absis (sumbu X) */
    float Y;  /* ordinat (sumbu Y) */
} POINT;

/* Macro selektor komponen */
#define Absis(P)   (P).X
#define Ordinat(P) (P).Y

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y);
/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P);
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P);

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P);
float GetY(const POINT P);
void  SetX(POINT *P, float X);
void  SetY(POINT *P, float Y);

/* Mengecek lokasi POINT pada sumbu atau kuadran */
boolean IsOrigin(POINT P);     /* true jika P = (0,0) */
boolean IsOnSbX(POINT P);      /* true jika Y = 0 */
boolean IsOnSbY(POINT P);      /* true jika X = 0 */
int     Kuadran(POINT P);      /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */

/* Membandingkan dua POINT */
boolean Equals(POINT P1, POINT P2);   /* true jika X dan Y identik */
boolean NonEquals(POINT P1, POINT P2);/* negasi Equals */

/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float  Distance(POINT P1, POINT P2);
/* Menghasilkan titik tengah P1 dan P2 */
POINT  MidPoint(POINT P1, POINT P2);

#endif  /* POINT_H */
