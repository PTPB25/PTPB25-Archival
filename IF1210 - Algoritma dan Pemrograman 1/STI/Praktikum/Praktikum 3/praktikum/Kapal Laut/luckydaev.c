// #include <stdio.h>
// #define MAX 1000
// int main(){
//     int n, i, k,survivor;
//     scanf("%d %d %d", &n,&i,&k);
//     int array[MAX]={0};
//     i--;
//     for(int j = 0; j<n; j++){
//         array[j] = j+1;
//     }

//     while(n>1){
//         printf("%d %d\n", i, n);
//         for(int j = 0; j<n; j++){
//             printf("%d ", array[j]);
//         }
//         printf("\n");
//         for (int j = (i+k)%n; j<n; j++){
//             array[j] = array[j+1];
//         }
//         n--;
//         int j = k;
//         while(j>0){
//             i++;
//             if(i>=n) i = 0;
//             j--;
//         }
//     }

//     printf("%d\n", array[i]);
// }

#include <stdio.h>

#define MAX 1000

int main() {
    int n, i, k;
    scanf("%d %d %d", &n, &i, &k);
    i--;

    int alive[MAX];
    for (int j = 0; j < n; j++) {
        alive[j] = 1;
    }

    int count = n;
    while (count > 1) {
        int step = 0;
        while (step < k) {
            i = (i + 1) % n;
            if (alive[i]) step++;
        }

        alive[i] = 0;
        count--;

        while (!alive[i]) {
            i = (i + 1) % n;
        }
    }

    for (int j = 0; j < n; j++) {
        if (alive[j]) {
            printf("%d\n", j + 1);
            break;
        }
    }

    return 0;
}

// #include <stdio.h>

// int main() {
//     int n, i, k;
//     scanf("%d %d %d", &n, &i, &k);
//     i--;

//     int result = 0;
//     for (int j = 2; j <= n; j++) {
//         result = (result + k) % j;
//     }

//     result = (result + i) % n;
//     printf("%d\n", result + 1);

//     return 0;
// }