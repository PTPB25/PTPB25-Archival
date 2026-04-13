#include <stdio.h>

int cekMatang(int x){
    if(x>=0 && x<3) return 1;
    else if(x>2 && x<6) return 2;
    else if(x>5) return 3;
}

void printMatang(int x){
    switch (x)
    {
    case 1:printf("Kategori: Mentah\n");break;
    case 2:printf("Kategori: Matang\n");break;
    case 3:printf("Kategori: Terlalu matang\n");break;
    default:
        break;
    }
}

void printStat(int tah, int tang, int ter){
    printf("Laporan Kematangan Pisang\n");
    printf("Mentah: %d\nMatang: %d\nTerlalu matang: %d\n", tah, tang, ter);
}

int main(){
    int N;
    int mentah = 0, matang = 0, terlalu = 0;

    scanf("%d",&N);

    for(int i = 0 ; i<N;i++){
        int done = 0;
        int inp1, inp2, buffer;
        while (!done){
            int ref = 0;
            for(;;){
                scanf("%d", &inp1);
                if(inp1 == 1 || inp1 == 2) break;
                printf("Input salah. Masukkan kembali input dengan benar.\n");
            } // for
            //int ref = inp1;
            if (inp1 == 1){
                scanf("%d", &inp2);
                printMatang(cekMatang(inp2));

                switch(cekMatang(inp2)){
                    case 1: mentah++;break;
                    case 2: matang++;break;
                    case 3: terlalu++;break;
                }
                done = 1;
                //scanf(" %d",&buffer);
                //printStat(mentah, matang, terlalu);
                // i--;
                // break;
            }
            else{
                printStat(mentah, matang, terlalu);
                scanf("%*[^\n]");
                scanf("%*c");
                i--;
                done = 1;
            }//else
            
        } // while
    }

    printf("Program selesai\n");
}