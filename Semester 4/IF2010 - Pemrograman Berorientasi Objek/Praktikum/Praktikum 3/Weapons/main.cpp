#include "WeaponInventory.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  WeaponInventory inventory;

  while (q--) {
    int cmd;
    cin >> cmd;

    if (cmd == 1) {
      string id, name, type;
      int damage, rarity;
      cin >> id >> name >> type >> damage >> rarity;
      if (inventory.find(id) == nullptr) {
        inventory.add(id, name, type, damage, rarity);
      } else {
        inventory.update(id, name, type, damage, rarity);
      }
      cout << "OK\n";
    } else if (cmd == 2) {
      string id;
      cin >> id;
      cout << (inventory.remove(id) ? "DELETED\n" : "NOT FOUND\n");
    } else if (cmd == 3) {
      string id;
      cin >> id;
      const Weapon *w = inventory.find(id);
      if (w == nullptr) {
        cout << "NOT FOUND\n";
      } else {
        cout << w->id << "|" << w->name << "|" << w->type << "|" << w->damage
             << "|" << w->rarity << "\n";
      }
    } else if (cmd == 4) {
      inventory.sort();
      cout << "SORTED\n";
    } else if (cmd == 5) {
      string type;
      cin >> type;
      cout << inventory.totalDamage(type) << "\n";
    } else if (cmd == 6) {
      int minRarity;
      cin >> minRarity;
      cout << inventory.countByRarity(minRarity) << "\n";
    } else if (cmd == 7) {
      string type;
      cin >> type;
      inventory.printByType(type);
      cout << "END\n";
    } else if (cmd == 8) {
      inventory.print();
      cout << "END\n";
    } else if (cmd == 9) {
      string type;
      int bonusDamage;
      cin >> type >> bonusDamage;
      int count = inventory.upgradeAll(type, bonusDamage);
      cout << count << " UPGRADED\n";
    }
  }

  return 0;
}
