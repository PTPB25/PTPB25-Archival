#include <stdio.h>


int Total(int a, int b, int c, int d, int e){
    return (a+b+c+d+e);
}

double Rerata(double a, double b, double c, double d, double e){
    return (a+b+c+d+e)/5;
}

int main(){
    int a, b, c, d, e;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    int total = Total(a, b, c, d, e);
    double rerata = Rerata(a, b, c, d, e);
    printf("%d\n", total);
    printf("%lf\n", rerata);
    if(rerata >= 10.0){
        printf("Pesta Nimons Sukses!\n");
    }
    else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}