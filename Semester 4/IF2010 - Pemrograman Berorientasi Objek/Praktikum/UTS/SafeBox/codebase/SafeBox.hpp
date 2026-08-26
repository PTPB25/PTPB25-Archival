#ifndef SAFE_BOX_HPP
#define SAFE_BOX_HPP

#include <iostream>
#include <functional>
#include "SafeBoxException.hpp"
// include header lain jika diperlukan (stack, vector, algorithm, etc.)

using namespace std;

// Template class SafeBox<T>:
// Menyimpan elemen bertipe T secara LIFO dengan kapasitas terbatas.
// Implementasi internal dibebaskan, dapat menggunakan stack, vector, atau struktur data lain sesuai kebutuhan.
template<typename T>
class SafeBox {
    // TODO: deklarasikan atribut private yang diperlukan
public:
    // Inisialisasi box dengan kapasitas maksimum dan validator opsional.
    // Jika validator diberikan, store() akan melempar InvalidItemException
    // untuk item yang tidak lolos validasi.
    SafeBox(int capacity, function<bool(const T&)> validator = nullptr);

    // Menyimpan item ke dalam box.
    // Lakukan hal berikut secara berurutan:
    // 1. Lempar InvalidItemException jika validator ada dan item tidak valid.
    // 2. Lempar BoxFullException(cap) jika items.size() >= cap.
    // 3. Tambahkan item ke box jika valid
    // Hint: Gunakan validator(item) untuk validasi, dan periksa apakah validator tidak nullptr sebelum dipanggil.
    void store(const T& item);

    // Mengambil dan menghapus item teratas (LIFO).
    // Lempar BoxEmptyException jika kosong.
    T retrieve();

    // Melihat item teratas tanpa menghapusnya.
    // Lempar BoxEmptyException jika kosong.
    T peek() const;

    // Membalik urutan semua elemen dalam box.
    // Lempar BoxEmptyException jika box kosong saat dipanggil.
    void reverse();

    // Mengembalikan jumlah item saat ini.
    int size() const;

    // Mengembalikan kapasitas maksimum box.
    int capacity() const;

    // Mengembalikan true jika box kosong.
    bool isEmpty() const;

    // Mencetak isi box dari bawah ke atas: [item_bawah, ..., item_atas]
    // Jika kosong, cetak [].
    friend ostream& operator<<(ostream& os, const SafeBox<T>& box) {
        // TODO
    }
};

// Template function safeMerge:
// Memindahkan item dari src ke dst satu per satu (urutan LIFO).
// Hentikan jika dst penuh (tangkap BoxFullException secara internal).
// Kembalikan jumlah item yang berhasil dipindahkan.
template<typename T>
int safeMerge(SafeBox<T>& src, SafeBox<T>& dst) {
    // TODO
}

#endif
