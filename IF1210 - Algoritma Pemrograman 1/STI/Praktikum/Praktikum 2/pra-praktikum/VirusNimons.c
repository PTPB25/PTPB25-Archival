#include <stdio.h>

long replikasiVirus(long init, long rep, long time){
    long induk = init;
    long indukdone = 0;

    for(int i = 0; i<time; i++){
        
        //Awal mereplikasi sebanyak X, sel induk yang sudah mereplikasi tidak mereplikasi lagi, hasil dari replikasi
        //menjadi sel induk selanjutnya. Didapatkan total sel induk setiap jam = induk*replikasi - induksebelum
        long selBaru = induk * rep;
        indukdone += induk;
        induk = selBaru;

        //printf("%d %d %d\n",induk, indukdone);
    }

    return induk +=indukdone;
}
long N, T, X;

int main(){
    scanf("%ld\n%ld\n%ld",&N,&T,&X);
    printf("Terdapat %ld Virus Nimons Gila pada jam ke-%ld\n",replikasiVirus(N,X,T), T);
}