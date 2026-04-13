#ifndef PENGANAN_H
#define PENGANAN_H

class Penganan {
  public:
    // ctor tanpa parameter
    // inisialisasi seluruh koefisien dengan nilai 0
    Penganan();

    // ctor dengan parameter
    Penganan(int keik, int panekuk);
    
    //mengembalikan bagian jumlah keik
    int GetKeik() const;

    // mengembalikan bagian jumlah panekuk
    int GetPanekuk() const;

    // mengisi bagian keik
    void SetKeik(int);

    // mengisi bagian panekuk
    void SetPanekuk(int);

    // operator overloading

    // operator+ 
    friend Penganan operator+ (const Penganan&, const Penganan&);

    // operator- 
    friend Penganan operator- (const Penganan&, const Penganan&);

    // operator^ 
    friend Penganan operator^ (const Penganan&, const int);

    // operator^ (sifat komutatif)
    friend Penganan operator^ (const int, const Penganan&);

    // mengembalikan jumlah uang yang diperoleh
    static int JumlahUang();

    // mengembalikan jumlah kunjungan ke rumah
    static int HitungNRumah();

    // mencetak isi kantong
    // Jangan lupa tambahkan endline di akhir print
    // Contoh:
    // 0keik-0panekuk
    // 111keik-122panekuk
    void Print();

  private:
    static int uang;
    static int n_rumah;
    int keik;
    int panekuk;
};

#endif