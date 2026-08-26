#include <iostream>
#include <vector>
#include "Player.hpp"
#include "Banner.hpp"
#include "GachaSystem.hpp"
#include "GachaException.hpp"
#include "OutputFormatter.hpp"

using namespace std;

int main() {
    Player p("Cipher", 500);
    int currentDate = 20260325;
    int pullCost = 160;

    // Setup Banner
    vector<Banner> banners = {
        Banner("Standard Banner", 20991231, 10),
        Banner("Summer Event Banner", 20260324, 5),
        Banner("Weapon Banner", 20261231, 0),
        Banner("Premium Banner", 20261231, 5),
        Banner("Beginner Banner", 20261231, 5),
        Banner("Special Banner", 20991231, 5)
    };

    // Saatnya Gacha!!
    for (auto& banner : banners) {
        OutputFormatter::printPullStart(p.getName(), banner.getName());

        /*
         * ----------------------------------------------------------------------
         * POLYMORPHIC EXCEPTION HANDLING
         * ----------------------------------------------------------------------
         * GachaSystem berpotensi melempar 3 JENIS EXCEPTION berbeda:
         * 1. InsufficientGemsException (lempar dari Player)
         * 2. BannerExpiredException    (lempar dari Banner lalu RAII Rollback)
         * 3. ItemSoldOutException      (lempar dari Banner lalu RAII Rollback)
         *
         * try {
         *     code block 1
         * } catch (ExceptionClass& e) {
         *     code block 2
         * }
         *
         * try-catch akan mencoba menangkap semua objek bertipe ExceptionClass yang
         * dilempar oleh code block 1. Lalu code block 2 akan dieksekusi. Kita juga
         * dapat menggunakan object exception tersebut pada code block 2 dengan
         * menggunakan e (bisa nama lain, tapi biasanya e). Jangan lupa ganti ExceptionClass
         * sesuai dengan nama kelas exception kalian ya!
         *
         * Mengapa menggunakan Referensi (&)?
         * Agar sifat override method/polymorphism dari objek asli tetap ada
         * (Mencegah "Object Slicing"), saat `objectName.getErrorCode()` dipanggil.
         * ----------------------------------------------------------------------
         */

        // TODO: Buat blok try-catch
        // Di dalam try, lakukan performPull (baca GachaSystem), jika tidak ada exception maka printPullSuccess
        // Catch semua GachaException
        // Jika terjadi exception, lakukan printPullFailed dan printRollbackLog
        try {
            GachaSystem::performPull(p, banner, pullCost, currentDate);
            OutputFormatter::printPullSuccess(p.getGems());
        }
        catch (GachaException& e) {
            OutputFormatter::printPullFailed(e);
        }

        OutputFormatter::printSeparator();
    }

    return 0;
}
