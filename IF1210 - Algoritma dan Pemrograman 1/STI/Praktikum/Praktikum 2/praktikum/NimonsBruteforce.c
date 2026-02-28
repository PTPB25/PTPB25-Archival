#include "NimonsBruteforce.h"
#include <stdio.h>

/**
 * Fungsi untuk mendapatkan panjang angka 
 * 
 * kembalikan -1 jika angka == 0
 */
int length(int angka){
    int len = 0;
    if(angka==0) return -1;

    while (angka>=1){
        len++;
        angka/=10;
    }

    return len;
}

/**
 * Fungsi untuk mendapatkan digit ke-i dari kanan
 *
 * kembalikan -1 jika index > panjang atau index < 0
 */
int getDigit(int angka, int index){
    if(length(angka) < index || index < 0) return -1;

    for(int i = 1; i<index ; i++){
        angka /= 10;
    }

    return angka%10;
}

/**
 * Fungsi untuk menghapus digit ke-i dari kanan (misal: hapus index ke 2 dari 1234 -> 124)
 * 
 * kembalikan angka yang sama jika index > panjang atau index < 0
 */
int removeDigit(int angka, int index){
    if(index > length(angka) || index < 0) return angka;
    
    int tens = 1;
    for(int i = 0; i<index;i++){
        tens*=10;
    }
    int sisa = angka%(tens/10);
    //printf("%d %d\n", tens, sisa);

    return (angka/tens *(tens/10)) + sisa;
}

/**
 * Fungsi rekursif untuk mencari semua kombinasi angka
 */
void cariKombinasi(int angka, int current, int panjangAwal){
    if(length(current) == panjangAwal){
        printf("%d\n",current); 
        return;
    }

    int len = length(angka);

    for(int i = 1; i<=len; i++){
        int digit = getDigit(angka, i);

        if (digit == - 1) continue;

        int newCurrent = current * 10 + digit;
        int newAngka = removeDigit(angka,i);
        cariKombinasi(newAngka,newCurrent,panjangAwal);
    }

}

/**
 * Fungsi untuk menginisialisasi pemanggilan cariKombinasi
 */
void NimonBruteforce(int angka){
    int panjangAwal = length(angka);
    if (panjangAwal == -1){
        printf("0\n");
        return;
    }

    cariKombinasi(angka,0,panjangAwal);
}

//Ignore
// int main() {
//     int input;
//     scanf("%d", &input);
//     NimonBruteforce(input);
//     return 0;
// }