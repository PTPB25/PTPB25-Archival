
#include "arrayutils.h"

/**
 * @brief Mengurutkan array dalam urutan menaik.
 * @funfact, array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param arr Array yang akan diurutkan.
 * @param n Jumlah elemen dalam array.
 */
void sort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 * 
 * @param arr Array yang akan dicari.
 * @param n Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int arr[], int n, int target){
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}



/**
 * @brief Menghitung rata-rata elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Rata-rata elemen.
 */
double calculateAverage(int arr[], int n){
    double sum;
    int i;
    sum = 0;
    for(i=0; i<n; i++){
        sum += arr[i];
    }
    return sum/n;
}



/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Median dari elemen.
 */
int findMedian(int arr[], int n){
    int i;
    int copy[n];

    for(i=0; i<n; i++){
        copy[i] = arr[i];
    }
    sort(copy, n);

    if(n & 1){
        return copy[n/2];
    }
    return (copy[n/2] + copy[n/2 - 1]) / 2;
}



/**
 * @brief Menemukan modus dari elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int arr[], int n){
    int i, j, freq, mode, modeFreq;

    modeFreq = 0;
    mode = arr[0];
    for(i=0; i<n; i++){
        freq = 0;
        for(j=0; j<n; j++){
            if(arr[j] == arr[i]){
                freq++;
            }
        }
    
        if(freq > modeFreq || freq == modeFreq && arr[i] < mode){
            modeFreq = freq;
            mode = arr[i];
        }
    }

    return mode;

}



/**
 * @brief Menemukan elemen maksimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen maksimum dalam array.
 */
int findMax(int arr[], int n){
    int i, max;
    
    max = arr[0];
    for(i=1; i<n; i++){
        if(max < arr[i]){
            max = arr[i];
        }
    }
    
    return max;
}



/**
 * @brief Menemukan elemen minimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen minimum dalam array.
 */
int findMin(int arr[], int n){
    int i, min;

    min = arr[0];
    for(i=1; i<n; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    return min;

}



/**
 * @brief Membalikkan elemen dalam array.
 * 
 * @param arr Array yang akan dibalik.
 * @param n Jumlah elemen dalam array.
 */
void reverseArray(int arr[], int n){
    int i, temp;
    
    for(i=0; i< n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }

}
