#include "GachaSystem.hpp"
#include "GachaTransaction.hpp"

void GachaSystem::performPull(Player& player, Banner& banner, int pullCost, int currentDate) {
    /*
     * ----------------------------------------------------------------------
     * RAII & EXCEPTION PROPAGATION
     * ----------------------------------------------------------------------
     * Perhatikan bahwa kita SAMA SEKALI TIDAK menggunakan block try-catch di fungsi ini.
     * Fungsi ini bertindak sebagai Mid-Level Propagator.
     *
     * Alur Eksekusi:
     * 1. Objek `tx` dibuat. Proses ini langsung memotong gems (atau gagal dan melempar
     *    InsufficientGems).
     * 2. `banner.pullItem` dipanggil. Ini bisa melempar Expired atau SoldOut.
     *    Jika dilempar, fungsi ini akan seketika dihentikan paksa (abort)
     * 3. Karena berhenti paksa, objek stack `tx` harus dihancurkan. ~GachaTransaction otomatis
     *    dipanggil, mendeteksi belum di-commit, lalu me-refund gems. Exception
     *    kemudian lanjut propagate ke pemanggil utama (main.cpp).
     * 4. Jika tahap 2 aman, tahap 3 `tx.commit()` dipanggil, sehingga saat `tx` nanti hancur di
     *    akhir scope fungsi ini, destructor tidak me-refund uang.
     * ----------------------------------------------------------------------
     */

    GachaTransaction tx(player, pullCost);
    banner.pullItem(currentDate);
    tx.commit();
}
