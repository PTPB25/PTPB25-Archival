#include "listfilm.h"
#include <stdio.h>

void readNumber(List *L, int n) {
    char digit;
    for (int i = 0; i < n; i++) {
        scanf(" %c", &digit);
        InsVFirst(L, digit - '0');
    }
}

void printNumber(List L) {
    address P = First(L);
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
    }
    printf("\n");
}

/*
 * ALGORITMA:
1. Inisialisasi:
   - Buat linked list kosong untuk menyimpan hasil penjumlahan.
   - Siapkan pointer untuk mengakses elemen pertama dari kedua linked list input
(`L1` dan `L2`).
   - Inisialisasi variabel `carry` untuk menyimpan nilai sisa pembagian (jika
ada) dari penjumlahan digit.

2. Iterasi Penjumlahan:
   - Lakukan iterasi selama salah satu pointer (`P1` atau `P2`) tidak `Nil` atau
nilai `carry` lebih besar dari nol.
   - Pada setiap iterasi:
     - Tambahkan nilai digit dari `L1` (jika ada) ke variabel `sum`.
     - Tambahkan nilai digit dari `L2` (jika ada) ke variabel `sum`.
     - Tambahkan nilai `carry` ke variabel `sum`.
     - Hitung nilai baru untuk `carry` sebagai hasil pembagian `sum` dengan 10.
     - Hitung nilai digit hasil (`sum`) sebagai sisa pembagian `sum` dengan 10.
     - Masukkan nilai digit hasil ke linked list hasil (`result`).
 * */

List addNumbers(List L1, List L2) {
    int carry = 0;
    List result;
    CreateEmpty(&result);

    address P1 = L1.First;
    address P2 = L2.First;

    while(P2 != Nil || P1 != Nil){
        int buf1=0;
        if(P1 != Nil) buf1 = P1->info;
        int buf2=0;
        if(P2 != Nil) buf2 = P2->info;
        int tambah = buf1+ buf2 + carry;
        // printf("%d %d %d\n", buf1, buf2, carry);
        // printf("%d\n", tambah);
        if(P1 == Nil && P2 == Nil){
            carry = tambah;
        }else{
            if(tambah >= 10){
            if(tambah > 10)carry = tambah%10;
            else carry = 1;
            tambah -= 10;
            }else{
                carry = 0;
            }
        // printf("sesudah carry %d\n", tambah);
            
        }
        InsVFirst(&result, tambah);
            if(P1 != Nil) P1 = P1->next;
            if(P2 != Nil) P2 = P2->next;
    }
    // if(carry != 0) InsVFirst(&result, carry);
    
    return result;
}

int main() {
    int m, n;
    List num1, num2, result;

    CreateEmpty(&num1);
    CreateEmpty(&num2);
    CreateEmpty(&result);

    scanf("%d %d", &m, &n);

    readNumber(&num1, m);
    readNumber(&num2, n);

    result = addNumbers(num1, num2);

    printNumber(result);

    return 0;
}
