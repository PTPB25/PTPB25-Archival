#include <stdio.h>


/* Bubble sort for simplicity */
void sort(long long *arr, int n){
    long long temp;
    int i, j;

    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Return the biggest integer between a and b */
long long max(long long a, long long b){
    if(a > b) return a;
    return b;
}


/* Observation: we can make arr[i] the last uninfected if and only if we have at least one first infection on the right of i (i+1 ... n-1) and at least one first infection on the left of i (0 ... i-1) */
/* Strategy: try all possible i (0 <= i <= n-1) as the last uninfected, for each i find the highest score we can achieve */
/* Prefix and suffix max array will be used, such that prefix[i] = max(arr[0], arr[1], ..., arr[i]) and suffix[i] = max(arr[i], arr[i+1], ... , arr[n-1]) */

/* Time complexity: O(n^2) due to bubble sort, can be further optimized by using O(n logn) sorting */
/* Space complexity: O(n) */

int main(){
    const long long INT64_MIN = (1ll << 63);            /* most negative signed 64 bit integer */

    int n, k, i, j, numToChoose, skippedLeft, skippedRight, skippedCenter;
    long long ans, temp;
    scanf("%d %d", &n, &k);

    long long arr[n], sorted[n], prefix[n], suffix[n];    /* sorted[n] for a sorted copy of the input array */

    for(i=0; i<n; i++){
        scanf("%lld", arr+i);
        sorted[i] = arr[i];
    }

    /* Build the prefix */
    prefix[0] = arr[0];
    for(i=1; i<n; i++){
        prefix[i] = max(prefix[i-1], arr[i]);
    }

    /*Build the suffix */
    suffix[n-1] = arr[n-1];
    for(i=n-2; i>=0; i--){
        suffix[i] = max(suffix[i+1], arr[i]);
    }

    /* Edge case at k = 1, the only possible index for the last uninfected is 0 or n-1, try all i and consider it the first place we infect */
    if(k == 1){
        ans = arr[0] + arr[n-1];
        for(i=1; i<n-1; i++){
            ans = max(ans, arr[i] + max(arr[0], arr[n-1]));
        }  
    }  
    else{

        /* General case, use strategy described in the beginning */
        sort(sorted, n);
        ans = INT64_MIN;

        for(i=0; i<n; i++){
            temp = arr[i];

            /* Choose one on the left, and one on the right to infect first */
            if(i==0){
                temp += suffix[i+1];
                numToChoose = k - 1;
            }
            else if(i==n-1){
                temp += prefix[i-1];
                numToChoose = k - 1;
            }
            else{
                temp += prefix[i-1] + suffix[i+1];
                numToChoose = k - 2;
            }


            /* Using the remaining k we have, infect more only if its positive (otherwise, it will not add to the score) */
            /* we use the sorted array and go from index n-1 so we will take the biggest value first (greedy technique) */
            /* the "skipped" variable is used to avoid double counting */
            j = n-1;
            skippedLeft = 0;
            skippedRight = 0;
            skippedCenter = 0;
            while(sorted[j] > 0 && numToChoose > 0){
                if(i > 0 && sorted[j] == prefix[i-1] && !skippedLeft){
                    skippedLeft = 1;
                }
                else if(i < n-1 && sorted[j] == suffix[i+1] && !skippedRight){
                    skippedRight = 1;
                }
                else if(sorted[j] == arr[i] && !skippedCenter){
                    skippedCenter = 1;
                }
                else{
                    temp += sorted[j];
                    numToChoose--;
                }
                j--;
            }
            ans = max(ans, temp);
        }
    }

    printf("%lld\n", ans);

}