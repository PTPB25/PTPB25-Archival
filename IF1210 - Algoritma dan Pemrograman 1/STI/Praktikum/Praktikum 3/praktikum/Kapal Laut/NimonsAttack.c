#include "NimonsAttack.h"

// Fungsi untuk menghitung jarak langsung antara kapal ke pulau
// Hint: pythagoras
float hitungJarakKePulau(Kapal kapal, Koordinat pulau){
    return sqrt(pow((kapal.posisi.x - pulau.x),2) + pow((kapal.posisi.y - pulau.y),2));
}

// Fungsi untuk menghitung jarak langsung antara dua kapal
float hitungJarakKeKapal(Kapal kapal1, Kapal kapal2){
    return sqrt(pow((kapal1.posisi.x - kapal2.posisi.x),2) + pow((kapal1.posisi.y - kapal2.posisi.y),2));
}

// Fungsi untuk mengecek apakah kapal valid
// Kapal valid jika tidak ada kapal lain yang memiliki koordinat sama dengan kapal tersebut dan tidak ada kapal lain yang memiliki kode yang sama
// Kapal valid jika tidak berada di pulau
boolean isKapalValid(Kapal kapal, Koordinat pulau, Kapal *listKapal, int N){
    if (hitungJarakKePulau(kapal, pulau) == 0) {
        printf("%s nabrak pulau dong!\n", kapal.kode);
        return FALSE;
    }

    for(int i = 0; i<N;i++){
        if(listKapal[i].posisi.x == kapal.posisi.x && listKapal[i].posisi.y == kapal.posisi.y ){
            printf("%s nabrak kapal lain dong!\n", kapal.kode);
            return FALSE;
        } 

        if(strcmp(listKapal[i].kode, kapal.kode) == 0) {
            printf("%s kok ada dua!\n",kapal.kode);
            return FALSE;
        }
    }

    return TRUE;
}

// Silakan gunakan algoritma bubble sorting
// Fungsi untuk mengurutkan kapal berdasarkan jarak terdekat ke pulau
void urutkanKapalTerdekat(Kapal *listKapal, Koordinat pulau, int N){
    for(int i = 0; i<N-1;i++){
        for(int j = 0; j<N-i-1; j++){
            if(hitungJarakKePulau(listKapal[j], pulau) > hitungJarakKePulau(listKapal[j+1], pulau)){
                Kapal temp = listKapal[j];
                listKapal[j] = listKapal[j+1];
                listKapal[j+1] = temp;
            }
        }
    }
}

// Fungsi untuk menerima input, mencari kapal terdekat, dan menampilkan hasil
void cariKapalTerdekat(){
    int N,R;
    Koordinat mackenbruh;
    scanf("%d %d %d %d", &N, &R, &mackenbruh.x, &mackenbruh.y);
    Kapal data[N];

    for(int i = 0; i<N; i++){
        boolean check = FALSE;
        Kapal temp;
        while(check==FALSE){
            scanf("%d %d %s", &temp.posisi.x, &temp.posisi.y, temp.kode);
            check = isKapalValid(temp,mackenbruh,data,N);
        }
        data[i] = temp;
    }

    urutkanKapalTerdekat(data,mackenbruh,N);

    for(int i = 0; i < N; i++){
        if(hitungJarakKePulau(data[i],mackenbruh) < R){
            printf("%d - %s (%d,%d)\n", i+1, data[i-1].kode, data[i-1].posisi.x, data[i-1].posisi.y);
        } else {
            printf("Perdamaian di pulau Mackenbruh telah usai :(\n");
            break;
        }
    }

    //dibawah hapus/komen aja kalau mau di submit
    //scanf("%d/n");
}