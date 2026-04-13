/* Enum untuk tipe gula */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NimonsCafe.h"

/* Constructor */

/**
 * Membuat pesanan minuman berdasarkan:
 * - nama minuman
 * - ukuran ('S', 'M', 'L')
 * - tipe gula (LESS_SUGAR, NORMAL_SUGAR, EXTRA_SUGAR)
 * - tipe es (LESS_ICE, NORMAL_ICE, NO_ICE)
 * 
 * Hint: Bisa gunakan method strcpy()
 * Contoh penggunaan:
 * strcpy(nimons.pekerjaan, pekerjaan);
 */
PesananMinuman BuatPesanan(char *nama, char ukuran, TipeGula tGula, TipeEs tEs){
    PesananMinuman pesanan;
    //Ingat fungsi butuhnya pointer ke PesananMinuman, bukan fieldnya (e.g pesanan.tipeGula)
    setNamaMinuman(&pesanan, nama);
    setUkuran(&pesanan, ukuran);
    setTipeEs(&pesanan,tEs);
    setTipeGula(&pesanan,tGula);
    return pesanan;
}

/* Getter & Setter */

/**
 * Return nama minuman
 */
char *getNamaMinuman(PesananMinuman *p){
    return p->namaMinuman;
}

/**
 * Mengubah nama minuman
 */
void setNamaMinuman(PesananMinuman *p, char *nama){
    strcpy(p->namaMinuman, nama);
}

/**
 * Return ukuran minuman
 */
char getUkuran(PesananMinuman p){
    return p.ukuran;
}

/**
 * Mengubah ukuran pesanan menjadi ukuran baru
 * Contoh: 
 * Mengubah ukuran minuman M menjadi S
 */
void setUkuran(PesananMinuman *p, char ukuran){
    p->ukuran=ukuran;
}

/**
 * Return Tipe Gula minuman
 */
TipeGula getTipeGula(PesananMinuman p){
    return p.tipeGula;
}

/**
 * Mengubah Tipe Gula minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeGula(PesananMinuman *p, TipeGula tGula){
    p->tipeGula=tGula;
}

/**
 * Return Tipe Es dari minuman
 */
TipeEs getTipeEs(PesananMinuman p){
    return p.tipeEs;
}

/**
 * Mengubah Tipe Es dari minuman
 * Contoh:
 * Mengubah tipe gula normal sugar menjadi less sugar
 */
void setTipeEs(PesananMinuman *p, TipeEs tEs){
    p->tipeEs = tEs;
}

/* Display */

/**
 * Menampilkan pesanan dalam format:
 * <namaMinuman> - <ukuran> - <tipeGula>, <tipeEs>
 * Contoh Output:
 * "Cappuccino - M - normal sugar, less ice"
 * 
 * PASTIKAN ADA ENDLINE DI AKHIR OUTPUT!
 */
void TulisPesanan(PesananMinuman p){
    printf("%s - %c - ", p.namaMinuman,p.ukuran, p.tipeGula, p.tipeEs);

    //Gula
    switch(p.tipeGula){
        case LESS_SUGAR: printf("less sugar");break;
        case NORMAL_SUGAR: printf("normal sugar");break;
        case EXTRA_SUGAR: printf("extra sugar");break;
    }

    printf(", ");

    //ES
    switch(p.tipeEs){
        case NORMAL_ICE:printf("normal ice"); break;
        case LESS_ICE:printf("less ice");break;
        case NO_ICE:printf("no ice");break;
    }

    printf("\n");

    /*Sebenernya bisa pakai array
    const char* gulaStr[] = {"less sugar", "normal sugar", "extra sugar"};
    const char* esStr[] = {"less ice", "normal ice", "no ice"};
    
    dan ngeprint dengan 

    printf("%s - %c - %s, %s\n", p.namaMinuman, p.ukuran, gulaStr[p.tipeGula], esStr[p.tipeEs]);
    (akses index array dari enum pesanan)
    */
}

/* Utility */

/**
 * Menghitung total kalori berdasarkan:
 * - Ukuran:
 *     S = 100 kalori
 *     M = 150 kalori
 *     L = 200 kalori
 * - Gula:
 *     LESS_SUGAR = +10 kalori
 *     NORMAL_SUGAR = +20 kalori
 *     EXTRA_SUGAR = +40 kalori
 * 
 * Return: nilai kalori dalam bilangan bulat
 */
int TotalKalori(PesananMinuman p){
    int kalori;
    int sugar;

    if (p.ukuran == 'S'){
        kalori = 100;
    }else if (p.ukuran == 'M'){
        kalori = 150;
    }else if (p.ukuran == 'L'){
        kalori = 200;
    }

    if(p.tipeGula == LESS_SUGAR){
        sugar = 10;
    }else if(p.tipeGula == NORMAL_SUGAR){
        sugar = 20;
    }else if(p.tipeGula == EXTRA_SUGAR){
        sugar = 40;
    }
    return kalori+sugar;
}

/**
 * Menghitung volume bersih (tanpa es) berdasarkan:
 * - Ukuran:
 *     S = 240 ml
 *     M = 360 ml
 *     L = 480 ml
 * - Es:
 *     volume es pada NORMAL_ICE = 25% dari volume ukuran
 *     volume es pada LESS_ICE = 10% dari volume ukuran
 *     volume es pada NO_ICE = 0% dari volume ukuran
 *
 * Return: volume bersih dalam bilangan bulat
 */
int VolumeBersih(PesananMinuman p){
    int voluk;
    int voles;
    if (p.ukuran == 'S'){
        voluk = 240;
    }else if (p.ukuran == 'M'){
        voluk = 360;
    }else if (p.ukuran == 'L'){
        voluk = 480;
    }

    if(p.tipeEs == NORMAL_ICE){
        voles = voluk/4;
    }else if(p.tipeEs == LESS_ICE){
        voles = voluk/10;
    }else if(p.tipeEs == NO_ICE){
        voles = 0;
    }
    return voluk - voles;
}