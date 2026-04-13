#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char input[6];
    int HH;
    int MM;
} Waktu;

typedef struct{
    char awal[6];
    char akhir[6];
    int menit;
} JamKencan;

int dromeCheck(int menit){
    int original = menit;
    int reverse = 0;
    while (menit>0){
        reverse*=10;
        reverse+=menit%10;
        menit/=10;
    }

    if(reverse==original) return 1;
    return 0;
}

int pairExists(JamKencan times[], int count, char* time1, char* time2, int diff) {
    for (int i = 0; i < count; i++) {
        if (strcmp(times[i].awal, time1) == 0 && 
            strcmp(times[i].akhir, time2) == 0 && 
            times[i].menit == diff) {
            return 1;
        }
    }
    return 0;
}

int main(){
    int N;
    scanf("%d",&N);
    Waktu data[N];

    for(int i = 0; i<N; i++){
        scanf("%s", data[i].input);
        data[i].HH = (data[i].input[0] - '0') * 10 + (data[i].input[1] - '0');
        data[i].MM = (data[i].input[3] - '0') * 10 + (data[i].input[4] - '0');
    }

    JamKencan times[1000];

    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int time_i_minutes = data[i].HH * 60 + data[i].MM;
            int time_j_minutes = data[j].HH * 60 + data[j].MM;
            int time_diff = abs(time_i_minutes - time_j_minutes);
            
            if (time_diff == 0) continue;
            
            if (dromeCheck(time_diff)) {
                char *earlier, *later;
                if (time_i_minutes < time_j_minutes) {
                    earlier = data[i].input;
                    later = data[j].input;
                } else {
                    earlier = data[j].input;
                    later = data[i].input;
                }
                
                if (!pairExists(times, index, earlier, later, time_diff)) {
                    strcpy(times[index].awal, earlier);
                    strcpy(times[index].akhir, later);
                    times[index].menit = time_diff;
                    index++;
                }
            }
        }
    }

    if (index == 0) {
        printf("Mungkin bukan hari ini. Jadi, Gro akan melamar Luiy pekan depan.\n");
    } else {
        printf("%s\n", times[0].awal);
        printf("[");
        for (int i = 0; i < index; i++) {
            printf("[(%s - %s), %d menit]", times[i].awal, times[i].akhir, times[i].menit);
            if (i < index - 1) {
                printf(", ");
            }
        }
        printf("]");
    }

}

