#include <stdio.h>
#include "MandiBola.h"

int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int hanak,hadew,halan;
    hanak = jumlah_anak * 10000;
    hadew = jumlah_dewasa * 20000;
    halan = jumlah_lansia * 15000;
    return hanak + hadew + halan;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    printf("Tiket berhasil dibeli!\nRincian:\n- Jumlah anak-anak: %d\n- Jumlah dewasa: %d\n- Jumlah lansia: %d\n- Total biaya: %d\n", jumlah_anak, jumlah_dewasa, jumlah_lansia, HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
    return;
}

void SelamatDatang(int input){
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");

    //masukkan jumlah peserta
    int aa, dew, lan;
    aa =  input % 10;    
    dew = (input / 10) % 10; 
    lan = input / 100;

    printf("Jumlah anak: %d\nJumlah dewasa: %d\nJumlah lansia: %d\n", aa, dew, lan);
    PrintTiket(aa,dew,lan);
    return;
}

void HandleNimonsHunting(long input){
    int jumlah_pergerakan, jumlah_lubang, jumlah_harta_karun,total_harta_karun = 0,jumlah_ditutup = 0,total_langkah = 0;
    //printf("%lld",input);
    jumlah_pergerakan = input % 10;
    jumlah_lubang = (input/10) %10;
    jumlah_harta_karun = (input/100) %10;
    input /= 1000;
    //printf("%lld",input);
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n\n");
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n",jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n",jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);

    printf("Langkah ke-1\n");
    if(input%10==0){
        printf("Nimons tidak bergerak\n");
    }
    if(input%10 > 0){
        printf("Nimons bergerak sejauh %d langkah\n",input%10);
        total_langkah += input%10;
    }
    input/=10;
    if(input%10==1){
        printf("Nimons menemukan harta karun!\n");
        total_harta_karun++;
    }
    input/=10;
    if(input%10==1){
        printf("Nimons menutup lubang!\n");
        jumlah_ditutup++;
    }
    input/=10;

    //printf("%d\n",jumlah_pergerakan);
    for(int i=2; i<=jumlah_pergerakan;i++){
        printf("Langkah ke-%d\n",i);
        if(input%10 == 0){
            printf("Nimons tidak bergerak\n");
        }
        if(input%10 > 0){
            printf("Nimons bergerak sejauh %d langkah\n",input%10);
            total_langkah += input%10;
        }
        input /= 10;
        if(input%10 == 1){
            printf("Nimons menemukan harta karun!\n");
            total_harta_karun++;
        }
        input /= 10;
        if(input%10 == 1){
            printf("Nimons menutup lubang!\n");
            jumlah_ditutup++;
        }
        input /= 10;

    }

    //input jadi harga disini
    printf("\nTotal lubang yang ditutup: %d dari %d lubang\n", jumlah_ditutup, jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n",total_harta_karun);
    printf("Total harga harta karun yang ditemukan: %d\n", total_harta_karun*input*5);
    printf("Total langkah yang ditempuh: %d\n",total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n",input*jumlah_ditutup);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n",(total_harta_karun*input*5) - (input*jumlah_ditutup) );
    return;
}

// int main() {
//     int input_1;
//     long input_2;
//     scanf("%d", &input_1);
//     scanf("%lld", &input_2);
//     SelamatDatang(input_1);
//     HandleNimonsHunting(input_2);
//     return 0;
// }