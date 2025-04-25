
#include <stdio.h>
#include <math.h>
#include "point.h"

/* Membentuk POINT P dengan komponen X dan Y */
void CreatePoint(POINT *P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

/* Membaca nilai POINT dari stdin: masukkan X Y */
void BacaPOINT(POINT *P){
    float x, y;
    scanf("%f %f", &x, &y);
    CreatePoint(P, x, y);
}
/* Menulis POINT ke stdout dalam format "(X,Y)" */
void TulisPOINT(POINT P){
    printf("(%f,%f)", Absis(P), Ordinat(P));
}

/* Mengambil / mengubah komponen X dan Y */
float GetX(const POINT P){
    return Absis(P);
}
float GetY(const POINT P){
    return Ordinat(P);
}
void SetX(POINT *P, float X){
    Absis(*P) = X;
}
void SetY(POINT *P, float Y){
    Ordinat(*P) = Y;
}

/* Mengecek lokasi POINT pada sumbu atau kuadran */

/* true jika P = (0,0) */
boolean IsOrigin(POINT P){
    return !P.X && !P.Y;
}   
/* true jika Y = 0 */
boolean IsOnSbX(POINT P){
    return !P.Y;
}     
/* true jika X = 0 */
boolean IsOnSbY(POINT P){
    return !P.X;
}   
 /* 1..4; prekondisi: P bukan origin dan tidak di sumbu */
int Kuadran(POINT P){
    boolean xpos = (P.X > 0);
    boolean ypos = (P.Y > 0);
    if(xpos && ypos)return 1;
    else if(ypos)return 2;
    else if(xpos)return 4;
    else return 3;
}   

/* Membandingkan dua POINT */

 /* true jika X dan Y identik */
boolean Equals(POINT P1, POINT P2){
    float eps = 1e-6f;
    float diffx = P1.X - P2.X;
    float diffy = P1.Y - P2.Y;
    return -eps < diffx && diffx < eps && -eps < diffy && diffy < eps;
}
/* negasi Equals */
boolean NonEquals(POINT P1, POINT P2){
    return !Equals(P1, P2);
}


/* Menghitung jarak Euclidean antara P1 dan P2, Gunakan fungsi sqrtf dari math.h untuk menghitung akar kuadrat */
float Distance(POINT P1, POINT P2){
    float a = (P1.X - P2.X);
    float b = (P1.Y - P2.Y);
    return sqrtf(a*a + b*b);
}
/* Menghasilkan titik tengah P1 dan P2 */
POINT MidPoint(POINT P1, POINT P2){
    return (POINT){(P1.X + P2.X)/2, (P1.Y + P2.Y)/2};
}
