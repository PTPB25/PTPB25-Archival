#include <stdio.h>


int gcd(int a, int b){
    int temp;
    while(b > 0){
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(){
    int n, i, totalGCD, totalLCM, ans, result;
    scanf("%d", &n);
    if(n==0){
        printf("0\n");
    }
    else{
        int arr[n], prefGCD[n], prefLCM[n], suffGCD[n], suffLCM[n];     
        
        /* prefix-suffix gcd, lcm array approach for time efficiency (to achieve non quadratic time complexity) */
        /* other than this there are easier way, it is left as an exercise for the reader :) */

        for(i=0; i<n; i++){
            scanf("%d", arr+i);

            if(i > 0){
                prefGCD[i] = gcd(prefGCD[i-1], arr[i]);
                prefLCM[i] = (arr[i] * prefLCM[i-1]) / gcd(arr[i], prefLCM[i-1]);
            }
            else{
                prefGCD[i] = arr[i];
                prefLCM[i] = arr[i];
            }
        }

        suffGCD[n-1] = arr[n-1];
        suffLCM[n-1] = arr[n-1];
        for(i=n-2; i>=0; i--){
            suffGCD[i] = gcd(suffGCD[i+1], arr[i]);
            suffLCM[i] = (arr[i] * suffLCM[i+1]) / gcd(arr[i], suffLCM[i+1]);
        }

        ans = prefGCD[n-1] * prefLCM[n-1];       /* Default answer, no nimons are hidden*/
        for(i=0; i<n; i++){                      /* then try hiding nimons at each index [0..n-1] and see if the result is greater */
            if(i == 0 && i == n-1){
                totalGCD = arr[i];
                totalLCM = arr[i];
            }
            else if(i==0){
                totalGCD = suffGCD[i+1];
                totalLCM = suffLCM[i+1];
            }
            else if(i==n-1){
                totalGCD = prefGCD[i-1];
                totalLCM = prefLCM[i-1];
            }
            else{
                totalGCD = gcd(prefGCD[i-1], suffGCD[i+1]);
                totalLCM = prefLCM[i-1] * suffLCM[i+1] / gcd(prefLCM[i-1], suffLCM[i+1]);
            }

            result = totalGCD * totalLCM;
            if(result > ans){
                ans = result;
            }
        }

        printf("%d\n", ans);

    }
    return 0;
}