#ifndef CLOUD_NODE_HPP
#define CLOUD_NODE_HPP

class CloudNode {
    // Silakan deklarasikan atribut-atribut sesuai dengan spesifikasi
    // dan sesuai prinsip encapsulation.
    // CloudNode memiliki atribut:
    // - server_name (string): Nama dari node cloud.
    // - used_gb (int): Jumlah GB yang sudah digunakan.
    // - limit_gb (int): Batas maksimal GB yang dapat digunakan.

    // Definisikan 4 Sekawan:
    // 1. Constructor:
    //    Menerima nama server dan limit GB, inisialisasi used_gb ke 0.
    //    print pesan constructor dari Formatter.
    // 2. Copy Constructor: Membuat backup dari CloudNode (other).
    //    Nama server diikuti "_backup" (append server_name other)
    //    limit_gb sama
    //    used_gb diinisialisasi ke 0.
    //    print pesan copy constructor dari Formatter.
    // 3. Assignment Operator:
    //    Menyalin used_gb dari CloudNode lain ditambah dua, tetapi tidak boleh melebihi limit_gb.
    //    limit_gb sama.
    //    Nama server tidak berubah.
    //    print pesan assignment operator dari Formatter sebelum ekspresi return.
    // 4. Destructor:.
    //    print pesan destructor dari Formatter.

    // Definisikan 2 operator overloading:
    // 1. operator+ (CloudNode + int):
    //    Menambah limit_gb sebanyak n GB (int), mengembalikan CloudNode baru dengan perubahan tersebut.
    // 2. operator- (CloudNode - int):
    //    Mengurangi used_gb sebanyak n GB (int), tidak boleh kurang dari 0 (set ke 0 jika hasilnya negatif).
    //    Mengembalikan CloudNode baru dengan perubahan tersebut.

    // Definisikan fungsi friend void systemWipe(CloudNode &node):
    // Menerima referensi ke CloudNode, mengatur used_gb dan limit_gb ke 0.

    // Setelah mendeklarasikan kelas ini,
    // Buat implementasi di CloudNode.cpp.

    // Fungsi Getter, tidak perlu diubah
    int getUsedGB() const { return used_gb; }
    int getLimitGB() const { return limit_gb; }
};

#endif
