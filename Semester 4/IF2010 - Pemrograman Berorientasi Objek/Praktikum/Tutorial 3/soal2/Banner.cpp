#include "Banner.hpp"
#include "GachaException.hpp"

Banner::Banner(std::string name, int expiryDate, int itemCount)
    : name(name), expiryDate(expiryDate), itemCount(itemCount) {}

std::string Banner::getName() const {
    return name;
}

int Banner::getExpiryDate() const {
    return expiryDate;
}

int Banner::getItemCount() const {
    return itemCount;
}

void Banner::validateExpiryDate(int currentDate) const {
    // TODO 1: Validasi tanggal menggunakan currentDate.
    // Jika currentDate melewati expiryDate (>),
    // lemparkan BannerExpiredException.
    // Asumsi format date selalu benar.
    if(currentDate > expiryDate) throw BannerExpiredException();
}

void Banner::validateItemAvailability() const {
    // TODO 2: Validasi ketersediaan item.
    // Jika item sudah habis (<= 0),
    // lemparkan ItemSoldOutException.
    if(itemCount <= 0) throw ItemSoldOutException();
}

void Banner::pullItem(int currentDate) {
    /*
     * ----------------------------------------------------------------------
     * EXCEPTION PROPAGATION
     * ----------------------------------------------------------------------
     * Anda dapat memanggil kedua fungsi validasi di atas dan
     * TIDAK PERLU menangkap (try-catch) exception yang
     * berpotensi dilemparkan oleh fungsi-fungsi tersebut.
     *
     * Saat `validateExpiryDate()` atau `validateItemAvailability()` menemui error
     * lalu menjalankan instruksi `throw`, eksekusi program di dalam fungsi
     * `pullItem()` ini akan SEKETIKA BERHENTI
     *
     * Exception tersebut akan propagate melewati pullItem()
     * dan terus menuju fungsi pemanggil (contohnya di GachaSystem / Main)
     * hingga akhirnya ditangkap oleh sebuah blok `catch`.
     * ----------------------------------------------------------------------
     */

    // TODO 3: Validasi dengan fungsi validasi yang telah dibuat.
    // Cek expired lalu item availability
    // Jika exception tidak terjadi, gacha berhasil, itemCount berkurang 1
    validateExpiryDate(currentDate);
    validateItemAvailability();
    itemCount--;
}
