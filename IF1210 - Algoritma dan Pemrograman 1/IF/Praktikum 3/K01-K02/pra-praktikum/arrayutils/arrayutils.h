#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

/**
 * @brief Mengurutkan array dalam urutan menaik.
 * @funfact, array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param arr Array yang akan diurutkan.
 * @param n Jumlah elemen dalam array.
 */
void sort(int arr[], int n);

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 * 
 * @param arr Array yang akan dicari.
 * @param n Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int arr[], int n, int target);

/**
 * @brief Menghitung rata-rata elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Rata-rata elemen.
 */
double calculateAverage(int arr[], int n);

/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Median dari elemen.
 */
int findMedian(int arr[], int n);

/**
 * @brief Menemukan modus dari elemen dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int arr[], int n);

/**
 * @brief Menemukan elemen maksimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen maksimum dalam array.
 */
int findMax(int arr[], int n);

/**
 * @brief Menemukan elemen minimum dalam array.
 * 
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen minimum dalam array.
 */
int findMin(int arr[], int n);

/**
 * @brief Membalikkan elemen dalam array.
 * 
 * @param arr Array yang akan dibalik.
 * @param n Jumlah elemen dalam array.
 */
void reverseArray(int arr[], int n);

#endif