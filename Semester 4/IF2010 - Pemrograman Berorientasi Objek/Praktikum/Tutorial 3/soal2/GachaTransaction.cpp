#include "GachaTransaction.hpp"

// TODO 1: Implementasikan Constructor
// Saat transaksi dibuat, langsung kurangi gems dari akun pemain.
// Note: Jika pengurangan gems gagal (karena kurang), deductGems() akan melempar
// InsufficientGemsException. Jika itu terjadi, objek Konstruktor ini "gagal dibuat",
// dan destructornya TIDAK akan dipanggil. Ini behavior yang tepat karena
// gemsnya memang belum sempat terpotong karena exception.

// GachaTransaction(...) {...}
GachaTransaction::GachaTransaction(Player& p, int cost): player(p), cost(cost), isCommitted(false) {
    player.deductGems(cost);
}


// TODO 2: Tandai Commit Sukses
void GachaTransaction::commit() {
    // Ubah flag isCommitted
    isCommitted = true;
}


// TODO 3: Implementasikan Destructor untuk Rollback/Cleanup
GachaTransaction::~GachaTransaction() {
    /*
     * ----------------------------------------------------------------------
     * RAII (Resource Acquisition Is Initialization) & Stack Unwinding
     * ----------------------------------------------------------------------
     * Dalam C++, jika sebuah exception dilempar, sistem akan melakukan "Stack Unwinding".
     * Stack Unwinding berarti semua objek LOKAL yang sudah dibuat di dalam scope tempat
     * exception itu terjadi akan DIHANCURKAN (Destructornya dipanggil) secara paksa.
     *
     * Sehingga, destructor bisa menjadi tempat untuk melakukan rollback/cleanup. Jika transaksi ini
     * TIDAK di-commit, itu artinya terjadi exception di tengah jalan, dan kita secara otomatis
     * dapat langsung mengembalikan gems yang terlanjur terpotong tadi.
     * ----------------------------------------------------------------------
     */

    // Jika BUKAN isCommitted (berarti gagal di tengah jalan), maka
    // tambah gems milik player untuk mengembalikan Gems sebesar cost.
    if(!isCommitted) {
        player.addGems(cost);
    }
}
