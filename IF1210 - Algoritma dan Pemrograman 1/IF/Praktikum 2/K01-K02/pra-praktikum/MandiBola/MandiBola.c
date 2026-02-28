#include <stdio.h>


int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    return 10000 * jumlah_anak + 20000 * jumlah_dewasa + 15000 * jumlah_lansia;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia){
    int total;

    total = HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia);
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", total);
}

void SelamatDatang(int input){
    int anak, dewasa, lansia;
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n");
    printf("\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n");
    printf("\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n");
    printf("\n");

    anak = input % 10;
    dewasa = (input / 10) % 10;
    lansia = (input / 100) % 10;
    printf("Jumlah anak: %d\n", anak);
    printf("Jumlah dewasa: %d\n", dewasa);
    printf("Jumlah lansia: %d\n", lansia);
    PrintTiket(anak, dewasa, lansia);
}


void HandleNimonsHunting(long input){
    int move, hole, treasure, i, step, isClosingHole, isFoundTreasure;
    int closedHole, foundTreasure, harga, stepSum;
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n");
    printf("\n");
    move = input % 10; input /= 10;
    hole = input % 10; input /= 10;
    treasure = input % 10 ; input /= 10;
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", move);
    printf("Jumlah lubang yang ada di kolam: %d\n", hole);
    printf("Jumlah harta karun yang ada di kolam: %d\n", treasure);

    stepSum = 0;
    foundTreasure = 0;
    closedHole = 0;
    for(i=1; i <= move; i++){
        step = input % 10; input /= 10;
        isFoundTreasure = input % 10; input /= 10;
        isClosingHole = input % 10; input /= 10;
        stepSum += step;
        printf("Langkah ke-%d\n", i);
        if(step == 0){
            printf("Nimons tidak bergerak\n");
        }
        else{
            printf("Nimons bergerak sejauh %d langkah\n", step);
        }
        if(isFoundTreasure){
            printf("Nimons menemukan harta karun!\n");
            foundTreasure++;
        }
        if(isClosingHole){
            printf("Nimons menutup lubang!\n");
            closedHole++;
        }
    }

    harga = input;   // sisa angka yang ada di input adalah harga
    printf("\n");
    printf("Total lubang yang ditutup: %d dari %d lubang\n", closedHole, hole);
    printf("Total harta karun yang ditemukan: %d\n", foundTreasure);
    printf("Total harga harta karun yang ditemukan: %d\n", harga * 5 * foundTreasure);
    printf("Total langkah yang ditempuh: %d\n", stepSum);
    printf("Total biaya ganti rugi Pak Gro: %d\n", harga * closedHole);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n", harga * (5 * foundTreasure - closedHole));
}


