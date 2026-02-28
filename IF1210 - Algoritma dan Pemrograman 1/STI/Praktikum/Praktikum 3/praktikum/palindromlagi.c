#include <stdio.h>
#include <string.h>

int main(){
    char data[1001];
    scanf("%s", data);
    int freq[128] = {0};

    for(int i = 0; data[i] != '\0'; i++){
        freq[data[i]]++;
    }

    int ganjil=0;
    for(int i = 0; i<128; i++){
        if(freq[i]%2!=0){
            ganjil++;
        }
    }

    if(ganjil<=1){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}