#include <stdio.h>
#include "TekaTeki.h"

long long kombinasi(int n, int k){
    
    long long a = k, b = n-k;
    long long maximal = a, minimal = b;
    
    if(b > a){
        maximal = b;
        minimal = a;
    }
    
    long long i, ans = 1;

    for(i = n; i > maximal; i--){
        ans *= i;
    }
    for(i = minimal; i >= 1; i--){
        ans /= i;
    }
    return ans;
}

long long catalan(int n){
    return kombinasi(2*n, n) / (n+1);
}
