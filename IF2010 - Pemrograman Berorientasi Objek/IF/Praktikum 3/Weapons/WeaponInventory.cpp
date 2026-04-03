#include "WeaponInventory.hpp"
#include <algorithm>
using namespace std;

/**
 * @brief Menambahkan senjata baru ke inventaris.
 * @param id ID unik senjata.
 * @param name Nama senjata.
 * @param type Tipe senjata (Sword/Bow/Staff).
 * @param damage Nilai damage senjata.
 * @param rarity Tingkat kelangkaan (1-5).
 */
void WeaponInventory::add(const string &id, const string &name, 
  const string &type, int damage, int rarity) {
    weapons.push_back(Weapon(id, name, type, damage, rarity));
}

/**
 * @brief Menghapus senjata berdasarkan id.
 * @param id ID senjata yang akan dihapus.
 * @return true jika senjata ditemukan dan dihapus, false jika tidak
 * ditemukan.
 */
bool WeaponInventory::remove(const string &id) {
  auto it = std::find_if(weapons.begin(), weapons.end(), [id](Weapon w) {
    return w.id == id;
  });
  if (it == weapons.end()) return false;
  weapons.erase(it);
  return true;
}

/**
 * @brief Mencari senjata berdasarkan id.
 * @param id ID senjata yang dicari.
 */
const Weapon *WeaponInventory::find(const string &id) const {
  auto it = std::find_if(weapons.begin(), weapons.end(), [id](Weapon w) {    
    return w.id == id;
  });
  if (it == weapons.end()) return nullptr;
  return &(*it);
}

/**
 * @brief Memperbarui data senjata yang sudah ada berdasarkan id.
 * @param id ID senjata target.
 * @param name Nama baru.
 * @param type Tipe baru.
 * @param damage Damage baru.
 * @param rarity Rarity baru.
 */
void WeaponInventory::update(const string &id, const string &name, const string &type, int damage, int rarity) {
  Weapon* w = std::find_if(weapons.begin(), weapons.end(), [id](Weapon w) {
  return w.id == id;
  }).base();
  *w = Weapon(id, name, type, damage, rarity);
}

/**
 * @brief Mengurutkan senjata.
 * @details Urutan: rarity menurun, jika sama damage menurun, jika masih sama id menaik (leksikografis).
 */
void WeaponInventory::sort() {
  std::sort(weapons.begin(), weapons.end(), [](Weapon a, Weapon b) {
    if (a.rarity != b.rarity) return a.rarity > b.rarity;
    else if (a.damage != b.damage) return a.damage > b.damage;
    else return a.id < b.id;
  });
}

/**
 * @brief Menghitung total damage semua senjata bertipe tertentu.
 * @param type Tipe senjata yang dihitung.
 * @return Total damage.
 */
long long WeaponInventory::totalDamage(const string &type) const {
  vector<int> v(weapons.size());
  transform(weapons.begin(), weapons.end(), v.begin(), [type](Weapon w) {
    if (w.type == type) return w.damage;
    else return 0;
  });
  return accumulate(v.begin(), v.end(), 0);
}

/**
 * @brief Menghitung jumlah senjata dengan rarity >= minRarity.
 * @param minRarity Batas minimum rarity.
 * @return Jumlah senjata yang memenuhi syarat.
 */
int WeaponInventory::countByRarity(int minRarity) const {
  return std::count_if(weapons.begin(), weapons.end(), [minRarity](Weapon val) { return (val.rarity >= minRarity); });
}

void printWeapon(Weapon w) {
  printf("%s|%s|%s|%d|%d\n", w.id.c_str(), w.name.c_str(), w.type.c_str(), w.damage, w.rarity);
}

/**
 * @brief Menampilkan semua senjata bertipe tertentu menggunakan iterator.
 * @param type Tipe senjata yang ditampilkan.
 * @details Cetak "EMPTY" jika tidak ada senjata bertipe tersebut.
 */
void WeaponInventory::printByType(const string &type) const {  
  int c = count_if(weapons.begin(), weapons.end(), [type](Weapon w) { return (w.type == type); });
  if (c == 0) cout << "EMPTY" << endl;
  else {
    for_each(weapons.begin(), weapons.end(), [type](Weapon w) {
      if (w.type == type) printWeapon(w);
    });
  }  
}

/**
 * @brief Menampilkan seluruh senjata sesuai urutan saat ini di container.
 * @details Cetak "EMPTY" jika container kosong.
 */
void WeaponInventory::print() const {
  if (weapons.size() == 0) cout << "EMPTY" << endl;
  for_each(weapons.begin(), weapons.end(), [](Weapon w) {
      printWeapon(w);
    });
}

/**
 * @brief Menambahkan bonus damage ke semua senjata bertipe tertentu.
 * @param type Tipe senjata yang di-upgrade.
 * @param bonusDamage Nilai tambahan damage.
 * @return Jumlah senjata yang ter-upgrade.
 */
int WeaponInventory::upgradeAll(const string &type, int bonusDamage) {
  transform(weapons.begin(), weapons.end(), weapons.begin(), 
    [type, bonusDamage](Weapon w) {
      Weapon w2 = w;
      if (w.type == type) w2.damage += bonusDamage;
      return w2;
    }
  );

  return  std::count_if(weapons.begin(), weapons.end(), [type](Weapon val) { return (val.type == type); });
}