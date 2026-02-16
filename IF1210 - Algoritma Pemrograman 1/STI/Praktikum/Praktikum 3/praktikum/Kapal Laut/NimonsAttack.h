#ifndef NIMONSATTACK_H
#define NIMONSATTACK_H

#define _INF 1000000000

#include "Boolean.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
} Koordinat;

typedef struct {
    Koordinat posisi;
    char kode[3];
} Kapal;

// Fungsi untuk menghitung jarak langsung antara kapal ke pulau
// Hint: pythagoras
float hitungJarakKePulau(Kapal kapal, Koordinat pulau);

// Fungsi untuk menghitung jarak langsung antara dua kapal
float hitungJarakKeKapal(Kapal kapal1, Kapal kapal2);

// Fungsi untuk mengecek apakah kapal valid
// Kapal valid jika tidak ada kapal lain yang memiliki koordinat sama dengan kapal tersebut dan tidak ada kapal lain yang memiliki kode yang sama
// Kapal valid jika tidak berada di pulau
boolean isKapalValid(Kapal kapal, Koordinat pulau, Kapal *listKapal, int N);

// Silakan gunakan algoritma bubble sorting
// Fungsi untuk mengurutkan kapal berdasarkan jarak terdekat ke pulau
void urutkanKapalTerdekat(Kapal *listKapal, Koordinat pulau, int N);

// Fungsi untuk menerima input, mencari kapal terdekat, dan menampilkan hasil
void cariKapalTerdekat();

#endif