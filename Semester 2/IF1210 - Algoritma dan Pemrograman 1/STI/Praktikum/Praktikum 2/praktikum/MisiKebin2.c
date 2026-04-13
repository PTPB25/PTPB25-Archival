#include <stdio.h>

int checkPrime(int x){
    if (x==1) return 0;
    if (x == 2 || x == 3) return 1;
    if (x%2==0 || x%3==0) return 0;
    else{
        for (int i = 5; i * i <= x; i+=6    ){
            if (x%i==0 || x%(i+2)==0) return 0;
        }
        return 1;
    }
}

int sumDigit(int x){
    int sum = 0;

    while (x>0){
        sum += x%10;
        //printf("%d\n",sum);
        x /=10;
    }
    return sum;
}

int Bingro(int x){
    int bilRo = 0;

    while(x>=1){
        bilRo *=10;
        bilRo+= x%2;
        x/=2;
    }

    while(bilRo%10 == 0){
        bilRo/=10;
    }

    return bilRo;
}

int main(){
    int A,B;
    int count = 0;

    scanf("%d %d",&A, &B);

    for(int i = A; i<=B; i++){
        if(checkPrime(i)){
            if(checkPrime(sumDigit(i))){
                count++;
            }
        }
    }

    printf("%d\n", Bingro(count));

    //printf("%d\n", sumDigit(999));
}