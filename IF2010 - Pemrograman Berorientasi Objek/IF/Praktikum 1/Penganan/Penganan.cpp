#include "Penganan.hpp"
#include <iostream>

int Penganan::n_rumah = 0;
int Penganan::uang = 0;

// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Penganan::Penganan() {
    keik = 0;
    panekuk = 0;
}

// ctor dengan parameter
Penganan::Penganan(int newKeik, int newPanekuk) {
    keik = newKeik;
    panekuk = newPanekuk;
}

//mengembalikan bagian jumlah keik
int Penganan::GetKeik() const {
    return keik;
}

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const {
    return panekuk;
}

// mengisi bagian keik
void Penganan::SetKeik(int newKeik) {
    keik = newKeik;
}

// mengisi bagian panekuk
void Penganan::SetPanekuk(int newPanekuk) {
    panekuk = newPanekuk;
}

// operator overloading

// operator+ 
Penganan operator+(const Penganan& left, const Penganan& right) {
    Penganan::n_rumah++;
    return Penganan(left.GetKeik() + right.GetKeik(), left.GetPanekuk() + right.GetPanekuk());
}

// operator- 
Penganan operator-(const Penganan& left, const Penganan& right) {
    int soldKeik = (right.GetKeik() <= left.GetKeik() ? right.GetKeik() : left.GetKeik());
    int soldPanekuk = (right.GetPanekuk() <= left.GetPanekuk() ? right.GetPanekuk() : left.GetPanekuk());

    Penganan::uang += soldKeik * 51 + soldPanekuk * 37;
    return Penganan(left.GetKeik() - soldKeik, left.GetPanekuk() - soldPanekuk);
}

// operator^ 
Penganan operator^(const Penganan& p, const int n) {
    int diffKeik = p.GetKeik() - n;
    if(diffKeik < 0) {
        Penganan::uang += diffKeik * 51;
        diffKeik = 0;
    }

    int diffPanekuk = p.GetPanekuk() - n;
    if(diffPanekuk < 0) {
        Penganan::uang += diffPanekuk * 37;
        diffPanekuk = 0;
    }

    return Penganan(diffKeik, diffPanekuk);
}

// operator^ (sifat komutatif)
Penganan operator^(const int n, const Penganan& p) {
    int diffKeik = p.GetKeik() - n;
    if(diffKeik < 0) {
        Penganan::uang += diffKeik * 51;
        diffKeik = 0;
    }

    int diffPanekuk = p.GetPanekuk()                - n;
    if(diffPanekuk < 0) {
        Penganan::uang += diffPanekuk * 37;
        diffPanekuk = 0;
    }

    return Penganan(diffKeik, diffPanekuk);
}

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang() {
    return Penganan::uang;
}

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah() {
    return Penganan::n_rumah;
}

// mencetak isi kantong
// Jangan lupa tambahkan endline di akhir print
// Contoh:
// 0keik-0panekuk
// 111keik-122panekuk
void Penganan::Print() {
    std::printf("%dkeik-%dpanekuk\n", keik, panekuk);
}
