
#include "operasi.h"
#include <stdio.h>

/* For testing */

int main(){
    char nama[50];
    int tekanan, detak, x, y;
    float saturasi;
    scanf("%s", nama);
    scanf("%d %d %f", &tekanan, &detak, &saturasi);
    scanf("%d %d", &x, &y);
    Pasien p = MakePasien(nama, MakeVital(tekanan, detak, saturasi), MakeLokasi(x, y));

    PrintPasien(p);
    ResetVital(&(p.v));
    PrintPasien(p);

}