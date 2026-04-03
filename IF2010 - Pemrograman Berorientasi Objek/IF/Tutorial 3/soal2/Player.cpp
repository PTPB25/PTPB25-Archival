#include "Player.hpp"
#include "GachaException.hpp"

Player::Player(std::string name, int initialGems) : name(name), gems(initialGems) {}

std::string Player::getName() const {
    return name;
}

int Player::getGems() const {
    return gems;
}

void Player::addGems(int amount) {
    // TODO 1: Implementasikan penambahan gems.
    // Fungsi menambah gems pemain sebanyak `amount`
    gems += amount;

    // Saat gacha gagal namun gems sudah berkurang, fungsi ini
    // akan dipanggil untuk mengembalikan (refund/rollback) saldo pemain.
}

void Player::deductGems(int amount) {
    // TODO 2: Implementasikan pengecekan validasi gems.
    // 1. Validasi apakah `gems` saat ini cukup untuk ditarik sejumlah `amount`?
    // 2. Jika tidak cukup, langsung lemparkan (throw) InsufficientGemsException.
    // 3. Jika cukup, kurangi `gems` sejumlah `amount`.
    if(gems < amount) throw InsufficientGemsException();
    gems -= amount;

    // TIDAK perlu menggunakan try-catch di fungsi ini.
    // Biarkan exception propagate.
}
