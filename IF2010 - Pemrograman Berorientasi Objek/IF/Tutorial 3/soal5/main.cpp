#include <iostream>
#include <string>
#include "RelicVault.hpp"

using namespace std;

void safePush(RelicVault& vault, const string& name) {
    try {
        vault.push(name);
    } catch (const InvalidRelicException&) {
        cout << "[LOG] Relic ditolak, coba dilihat lagi relicnya :)\n";
        throw;
    }
}

int main() {
    size_t capacity;
    int n;
    cin >> capacity >> n;

    RelicVault vault(capacity);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        try {
            if (command == "PUSH") {
                string name;
                cin >> name;
                vault.push(name);
                cout << "Menyimpan " << name << "\n";

            } else if (command == "SAFEPUSH") {
                string name;
                cin >> name;
                safePush(vault, name);
                cout << "Menyimpan " << name << "\n";

            } else if (command == "POP") {
                string item = vault.pop();
                cout << "Mengambil " << item << "\n";

            } else if (command == "TOP") {
                string top = vault.top();
                cout << "Relic teratas: " << top << "\n";

            } else if (command == "SIZE") {
                cout << "Jumlah relic: " << vault.size() << "\n";

            } else if (command == "CAPACITY") {
                cout << "Kapasitas vault: " << vault.capacity() << "\n";

            } else if (command == "EMPTY") {
                cout << (vault.empty() ? "Vault kosong" : "Vault tidak kosong") << "\n";
            }

        } catch (const FullVaultException& e) {
            cout << "[PENUH] " << e.what() << " | Kapasitas maks: " << e.getCapacity() << "\n";

        } catch (const InvalidRelicException& e) {
            cout << "[INVALID] " << e.what() << " | Relic: " << e.getRelicName() << "\n";

        } catch (const EmptyVaultException& e) {
            cout << "[KOSONG] " << e.what() << "\n";

        } catch (const VaultException& e) {
            cout << "[VAULT ERROR] " << e.what() << "\n";

        } catch (...) {
            cout << "[UNKNOWN ERROR]\n";
        }
    }

    return 0;
}