#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEGREE 100

/* ADT POLYNOMIAL
   ---------------
   Representasi polinomial dalam bentuk:
      P(x) = a_n * x^n + a_(n-1) * x^(n-1) + ... + a_1 * x + a_0
   Dimana:
     - 'degree' merupakan derajat tertinggi polinomial (n) yang memiliki koefisien bukan nol.
     - 'coef' adalah array yang menyimpan koefisien untuk masing-masing pangkat,
       yaitu coef[i] menyimpan koefisien untuk x^i.
*/
typedef struct
{
    int degree;               /* Derajat polinomial, yaitu pangkat tertinggi yang memiliki koefisien bukan nol */
    int coef[MAX_DEGREE + 1]; /* Array koefisien dari x^0 hingga x^(degree). coef[i] merupakan koefisien a_i */
} Polynomial;

/* --- Konstruktor dan Inisialisasi --- */
/*
   Fungsi: CreatePolynomial
   Deskripsi:
     Menginisialisasi sebuah polinomial P dengan derajat tertentu.
     Semua koefisien pada polinomial diinisialisasi ke nilai 0.
   I.S. (Initial State): P belum terdefinisi
   F.S. (Final State): P terdefinisi dengan nilai degree yang diberikan, dan seluruh koefisien bernilai 0.
   Contoh:
     Polynomial P;
     CreatePolynomial(&P, 3);
     // Hasil: P.degree = 3, dan P.coef[0..3] semuanya bernilai 0.
*/
void CreatePolynomial(Polynomial *P, int degree);

/* --- Input/Output Polinomial --- */
/*
   Fungsi: ReadPolynomial
   Deskripsi:
     Membaca input polinomial dari pengguna. Proses input dilakukan dengan langkah-langkah berikut:
       1. Membaca nilai derajat polinomial.
          Nilai derajat menentukan berapa banyak suku (pangkat) yang akan dibaca, yaitu dari 0 hingga derajat tersebut.
       2. Membaca koefisien (dalam bentuk integer) untuk setiap pangkat dari 0 hingga derajat yang telah ditentukan.
   I.S.: P sembarang.
   F.S.: P terdefinisi sesuai dengan input pengguna.
   Contoh:
     // Jika input dari pengguna adalah:
     // 2
     // 1
     // 2
     // 3
     // Maka polinomial yang terbentuk:
     // P.degree = 2, P.coef[0] = 1, P.coef[1] = 2, P.coef[2] = 3
     // yang merepresentasikan P(x) = 3x^2 + 2x + 1.
*/
void ReadPolynomial(Polynomial *P);

/*
   Fungsi: WritePolynomial
   Deskripsi:
     Menampilkan polinomial ke layar dalam format standar, misalnya:
       3x^3 + 2x^2 - x + 5
     Polinomial dicetak dari pangkat tertinggi ke pangkat 0. Koefisien dengan nilai 0 dilewati
     agar tampilan output lebih rapi.
   I.S.: P terdefinisi.
   F.S.: Polinomial ditampilkan pada layar.
   Contoh:
     // Misalkan P merupakan polinomial berikut:
     // P.degree = 3, P.coef[0] = 5, P.coef[1] = -1, P.coef[2] = 2, P.coef[3] = 3.
     // Maka fungsi WritePolynomial(P) akan menampilkan:
     // 3x^3 + 2x^2 - x + 5
*/
void WritePolynomial(Polynomial P);

/* --- Operasi Aritmatika Polinomial --- */
/*
   Fungsi: AddPolynomial
   Deskripsi:
     Menjumlahkan dua buah polinomial P1 dan P2. Proses penjumlahan dilakukan dengan
     menjumlahkan koefisien pada pangkat yang sama. Jika salah satu polinomial memiliki derajat
     yang lebih rendah, koefisien yang tidak ada dianggap sebagai 0.
   I.S.: P1 dan P2 terdefinisi.
   F.S.: Mengembalikan polinomial hasil penjumlahan P1 + P2, dengan derajat disesuaikan berdasarkan
         koefisien tertinggi yang bukan nol.
   Contoh:
     // Misalkan:
     // P1: P1.degree = 2, P1.coef = {1, 2, 3}   // Mewakili 3x^2 + 2x + 1
     // P2: P2.degree = 3, P2.coef = {4, 0, -1, 2} // Mewakili 2x^3 - x^2 + 4
     // Maka AddPolynomial(P1, P2) menghasilkan:
     // Hasil.degree = 3, Hasil.coef = {5, 2, 2, 2} yang merepresentasikan: 2x^3 + 2x^2 + 2x + 5.
*/
Polynomial AddPolynomial(Polynomial P1, Polynomial P2);

/*
   Fungsi: MultiplyPolynomial
   Deskripsi:
     Mengalikan dua buah polinomial P1 dan P2. Setiap koefisien pada P1 dikalikan dengan setiap
     koefisien pada P2, dan hasil perkalian ditempatkan pada pangkat yang merupakan penjumlahan
     indeks kedua koefisien yang dikalikan.
   I.S.: P1 dan P2 terdefinisi.
   F.S.: Mengembalikan polinomial hasil perkalian P1 * P2.
   Contoh:
     // Misalkan:
     // P1: P1.degree = 1, P1.coef = {1, 2}      // Mewakili 2x + 1
     // P2: P2.degree = 2, P2.coef = {3, 0, 4}    // Mewakili 4x^2 + 3
     // Maka MultiplyPolynomial(P1, P2) menghasilkan:
     // Hasil.degree = 3, Hasil.coef = {3, 6, 4, 8} yang merepresentasikan: 8x^3 + 4x^2 + 6x + 3.
*/
Polynomial MultiplyPolynomial(Polynomial P1, Polynomial P2);

/*
   Fungsi: EvaluatePolynomial
   Deskripsi:
     Mengevaluasi nilai polinomial P untuk suatu nilai x tertentu.
     Karena koefisien bertipe integer dan x juga merupakan integer,
     maka hasil evaluasi juga berupa integer.
   I.S.: P terdefinisi dan x merupakan bilangan integer.
   F.S.: Mengembalikan nilai hasil evaluasi P(x) dalam bentuk integer.
   Contoh:
     // Misalkan:
     // P: P.degree = 2, P.coef = {1, 2, 3}  // Mewakili 3x^2 + 2x + 1
     // Jika x = 2, maka EvaluatePolynomial(P, 2) menghasilkan:
     // Hasil = 3*(2^2) + 2*(2) + 1 = 3*4 + 4 + 1 = 12 + 4 + 1 = 17.
*/
int EvaluatePolynomial(Polynomial P, int x);

/*
   Fungsi: DerivativePolynomial
   Deskripsi:
     Menghitung turunan pertama dari polinomial P. Jika polinomial didefinisikan sebagai
       P(x) = a_n*x^n + ... + a_1*x + a_0,
     maka turunan P'(x) adalah:
       P'(x) = n*a_n*x^(n-1) + (n-1)*a_(n-1)*x^(n-2) + ... + 1*a_1.
     Apabila P merupakan polinomial konstan (degree 0), maka turunan yang dihasilkan adalah 0.
   I.S.: P terdefinisi.
   F.S.: Mengembalikan polinomial yang merupakan turunan pertama dari P.
   Contoh:
     // Misalkan:
     // P: P.degree = 3, P.coef = {1, -2, 3, 4}  // Mewakili: 4x^3 + 3x^2 - 2x + 1
     // Maka turunan P adalah:
     // Hasil.degree = 2, Hasil.coef = {-2, 6, 12} yang merepresentasikan:
     // P'(x) = 12x^2 + 6x - 2.
*/
Polynomial DerivativePolynomial(Polynomial P);

#endif