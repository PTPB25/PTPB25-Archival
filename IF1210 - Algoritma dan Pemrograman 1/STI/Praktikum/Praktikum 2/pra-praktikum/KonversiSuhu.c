#include <stdio.h>
#include <math.h>
//Fokus ke Celcius
double Konversi(double suhu, char satuan1, char satuan2){
    double hasil = suhu;

    if (satuan1 == 'K') hasil -= 273.15;
    else if (satuan1 == 'F') hasil = (suhu - 32) * 5 / 9;

    if (satuan2 == 'K') hasil += 273.15;
    else if (satuan2 == 'F') hasil = (hasil * 9 / 5) + 32;

    return hasil;
}

//Switch Case
// double Konversi(double suhu, char satuan1, char satuan2){
//     double hasil;
//     switch (satuan1)
//     {
//     case 'C':
//         if (satuan2=='F') hasil = (suhu*9/5)+32;
//         else if (satuan2=='K') hasil = suhu +=273.15;
//         break;
//     case 'F':
//         if (satuan2 == 'C') hasil = (suhu - 32) * 5 / 9;
//         else if (satuan2 == 'K') hasil = (suhu - 32) * 5 / 9 + 273.15;
//         break;
//     case 'K':
//         if (satuan2 == 'C') hasil = suhu - 273.15;
//         else if (satuan2 == 'F') hasil = ((suhu - 273.15) * 9 / 5) + 32;
//         break;

//     default:
//         //printf("Input tidak valid!");
//         break;
//     }
//     return hasil;
// }

//Nested loop
// double Konversi(double suhu, char satuan1, char satuan2){
//     double hasil;
//     if (satuan1 == 'C'){
//         if (satuan2 == 'F'){
//             hasil = (suhu * 9 / 5) + 32;
//         } else {
//             hasil = suhu + 273.15;
//         }
//     }

//     if (satuan1 == 'K'){
//         if (satuan2 == 'F'){
//             hasil = ((suhu - 273.15) * 9 / 5) + 32;
//         } else {
//             hasil = suhu - 273.15;
//         }
//     }

//     if (satuan1 == 'F'){
//         if (satuan2 == 'C'){
//             hasil = (suhu - 32) * 5 / 9;
//         } else {
//             hasil = (suhu - 32) * 5 / 9 + 273.15;
//         }
//     }

//     return hasil;
// }

int N;

int main(){
    scanf("%d",&N);
    double input, output[N];
    char s1, s2;

    for(int i = 0; i<N; i++){
        scanf("%lf %c %c", &input, &s1, &s2);
        output[i] = Konversi(input, s1, s2);
    }

    for(int i = 0; i<N; i++){
        printf("%.2lf\n", floor(output[i]));
    }

}