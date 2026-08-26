#ifndef CARGO_BAY_HPP
#define CARGO_BAY_HPP

#include "Item.hpp"
#include "CargoException.hpp"

template <class T>
class CargoBay {
private:
    Item<T>* arr;
    int capacity;
    int size;

public:
    // TODO Constructor & Destructor
    // Constructor: inisialisasi capacity, size = 0, alokasi array arr.
    // Destructor: Dealokasi array arr.
    CargoBay(int cap);
    ~CargoBay();

    // TODO Push & Pop (Standard)
    // push: Lempar CargoFullException jika size >= capacity. Taruh item ke index terakhir array
    // pop: Lempar CargoEmptyException jika size <= 0. Return item terakhir (LIFO) dan update size.
    void push(Item<T> item);
    Item<T> pop();

    // TODO extractItem
    // Cari item PERTAMA (dimulai dari index 0 hingga size-1)
    // yang nilai `data`-nya SAMA DENGAN `targetData`.
    // Jika ketemu:
    //     - Return Item tersebut.
    //     - Hapus Item tersebut dari array,
    //       lalu geser seluruh Item di kanannya ke kiri agar array tidak bolong.
    //     - Update size.
    // Jika tidak ketemu, lempar ItemNotFoundException.
    Item<T> extractItem(T targetData);

    // TODO forge
    // Menempa (Menggabungkan) dua Item teratas menjadi satu Item baru.
    // Cek apakah size < 2. Jika ya, lempar NotEnoughItemsException.
    // Jika aman, keluarkan (pop) item pertama dan item kedua.
    // Buatlah data baru hasil penjumlahan berurutan: `baseData` + data Top 1 + data Top 2.
    //   (Contoh: Jika baseData = "X", Top 1 = "Y", Top 2 = "Z", maka data baru = "XYZ").
    // Dipastikan tipe data T support operator+
    // Buatlah durability baru: rata-rata dari durability item pertama dan kedua (integer division).
    // Buat objek Item baru dengan data & durability baru tersebut, lalu push() ke CargoBay.
    void forge(T baseData);

    // TODO transferTo
    // Pindahkan sejumlah `count` item dari atas cargo `this` ke cargo `other`.
    // PROSES TRANSFER dilakukan satu per satu (LIFO).
    // Perhatikan bahwa urutan item akan terbalik.
    // Jika, size < count, lempar NotEnoughItemsException
    // PENANGANAN EXCEPTION:
    //    - Jika other ternyata penuh di tengah jalan (melempar CargoFullException),
    //      TANGKAP error tersebut dengan try-catch!
    //    - Kembalikan 1 item yang gagal masuk itu ke cargo `this`.
    //    - Lempar TransferFailedException ke luar fungsi untuk memberitahu bahwa transfer terhenti.
    void transferTo(CargoBay<T>& other, int count);
};

// Implementasi di sini (atau langsung di deklarasi methods juga bisa sih)
template <class T>
CargoBay<T>::CargoBay(int cap) : 
   capacity(cap), size(0), arr((Item<T>*)malloc(sizeof(Item<T>) * cap)) {
}
template <class T>
CargoBay<T>::~CargoBay() {
    delete arr;
}

template <class T>
void CargoBay<T>::push(Item<T> item) {
    if (size >= capacity) throw CargoFullException();
    arr[size++] = item;
}

template <class T>
Item<T> CargoBay<T>::pop() {
    if (size <= 0) throw CargoEmptyException();
    size--;
    return arr[size];
}

template <class T>
Item<T> CargoBay<T>::extractItem(T targetData) {
    int index = -1;
    bool found = false;
    for (int i = 0; i < size && !found; i++) {
        if (targetData == arr[i].getData()) {found = true; index = i;}
    }
    if (index == -1) throw ItemNotFoundException();

    Item<T> item = arr[index];
    
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    return item;
}

template <class T>
void CargoBay<T>::forge(T baseData) {
    if (size < 2) throw NotEnoughItemsException();

    Item<T> item1 = pop();
    Item<T> item2 = pop();

    T hasil = baseData + item1.getData() + item2.getData();
    int dur = (item1.getDurability() + item2.getDurability()) / 2;

    push(Item<T>(hasil, dur));
}

template <class T>
void CargoBay<T>::transferTo(CargoBay<T>& other, int count) {
    if (size < count) throw NotEnoughItemsException();

    Item<T> item;
    try {
        for (int i= 0; i < count; i++) {
            item = pop();
            other.push(item);
        }
    } catch (exception e) {
        push(item);
        throw TransferFailedException();
    }
}

#endif
