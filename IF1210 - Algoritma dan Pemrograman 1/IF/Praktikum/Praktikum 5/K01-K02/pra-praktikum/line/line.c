#include "line.h"
#include "point.h"
#include <math.h>
#include <stdio.h>


/* Kelompok konstruktor */
void CreateLine (LINE *L, POINT P1, POINT P2){
    PAwal(*L) = P1;
    PAkhir(*L) = P2;
}

/* Kelompok Baca-Tulis */
void BacaLINE(LINE *L){
    const float eps = 1e-6f;
    POINT P1, P2;
    scanf("%f %f", &(P1.X), &(P1.Y));
    scanf("%f %f", &(P2.X), &(P2.Y));
    while(fabsf(P1.X - P2.X) < eps  && fabsf(P1.Y - P2.Y) < eps){
        printf("Invalid Line\n");
        scanf("%f %f", &(P1.X), &(P1.Y));
        scanf("%f %f", &(P2.X), &(P2.Y));
    }
    CreateLine(L, P1, P2);
}


void TulisLINE (LINE L){
    POINT P1 = PAwal(L), P2 = PAkhir(L);
    printf("((%.2f,%.2f),(%.2f,%.2f))", P1.X, P1.Y, P2.X, P2.Y);
}

/* *** Kelompok operasi line *** */
float PanjangLINE (LINE L){
    POINT P1 = PAwal(L), P2 = PAkhir(L);
    float a = (P1.X - P2.X);
    float b = (P1.Y - P2.Y);
    return sqrtf(a*a + b*b);
    /* Panjang garis = jarak euclidean kedua point, d = sqrt((x1-x2)^2 + (y1-y2)^2) */
}

float Gradien (LINE L){
    POINT P1 = PAwal(L), P2 = PAkhir(L);
    return (P2.Y - P1.Y) / (P2.X - P1.X);
}

void GeserLINE (LINE *L, float deltaX, float deltaY){
    POINT P1 = PAwal(*L), P2 = PAkhir(*L);
    P1.X += deltaX; P2.X += deltaX;
    P1.Y += deltaY; P2.Y += deltaY;
    *L = (LINE){P1, P2};
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (LINE L1, LINE L2){
    const float eps = 1e-6f;
    return fabsf(Gradien(L1) * Gradien(L2) + 1) < eps;
}
boolean IsSejajar (LINE L1, LINE L2){
    const float eps = 1e-6f;
    return fabsf(Gradien(L1) - Gradien(L2)) < eps;
}
