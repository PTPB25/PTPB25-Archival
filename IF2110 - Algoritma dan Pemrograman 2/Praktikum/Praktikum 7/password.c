
#include "password.h"

int length(int angka){
    if(!angka) return -1;
    return (int)log10(angka) + 1;
}


int getDigit(int angka, int index){
    int n = length(angka);
    if(index < 0 || index >= n) return -1;
    
    while(index--){
        angka /= 10;
    }
    return angka % 10;
}


int removeDigit(int angka, int index){
    int n = length(angka);
    if(index < 0 || index >= n) return -1;

    int result = 0, power = 1;
    while(index--){
        result += (angka % 10) * power;
        angka /= 10;
        power *= 10;
    }

    angka /= 10;

    while(angka){
        result += (angka % 10) * power;
        angka /= 10;
        if(angka) power *= 10;
    }

    return result;
}


void cariKombinasi(int angka, int current, int panjangAwal){
    if(length(current) == panjangAwal) {
        printf("%d\n", current);
        return;
    }
    
    int n = length(angka);
    for (int i = 0; i < n; i++) {
        int digit = getDigit(angka, i);
        int newCurrent = current * 10 + digit;
        int newAngka = removeDigit(angka, i);
        cariKombinasi(newAngka, newCurrent, panjangAwal);
    }
}


void findPassword(int angka){
    cariKombinasi(angka, 0, length(angka));
}
