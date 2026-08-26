#include <iostream>
#include <string>
#include "SafeBoxException.hpp"
#include "SafeBox.hpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cap1, cap2, cap3;
    cin >> cap1 >> cap2 >> cap3;

    SafeBox<int> box1(cap1);
    SafeBox<int> box2(cap2);
    SafeBox<string> sbox(cap3, [](const string& s){ return (int)s.size() >= 2; });

    int q;
    cin >> q;

    while (q--) {
        string cmd;
        cin >> cmd;
        int n;

        if (cmd == "PUSH") {
            cin >> n;
            try {
                if (n == 1) { int v; cin >> v; box1.store(v); cout << "Tersimpan: " << v << "\n"; }
                else if (n == 2) { int v; cin >> v; box2.store(v); cout << "Tersimpan: " << v << "\n"; }
                else if (n == 3) { string v; cin >> v; sbox.store(v); cout << "Tersimpan: " << v << "\n"; }
            } catch (SafeBoxException& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "POP") {
            cin >> n;
            try {
                if (n == 1) { int v = box1.retrieve(); cout << "Diambil: " << v << "\n"; }
                else if (n == 2) { int v = box2.retrieve(); cout << "Diambil: " << v << "\n"; }
                else if (n == 3) { string v = sbox.retrieve(); cout << "Diambil: " << v << "\n"; }
            } catch (SafeBoxException& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "PEEK") {
            cin >> n;
            try {
                if (n == 1) cout << box1.peek() << "\n";
                else if (n == 2) cout << box2.peek() << "\n";
                else if (n == 3) cout << sbox.peek() << "\n";
            } catch (SafeBoxException& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "REVERSE") {
            cin >> n;
            try {
                if (n == 1) { box1.reverse(); cout << "Dibalik\n"; }
                else if (n == 2) { box2.reverse(); cout << "Dibalik\n"; }
                else if (n == 3) { sbox.reverse(); cout << "Dibalik\n"; }
            } catch (SafeBoxException& e) {
                cout << e.what() << "\n";
            }
        } else if (cmd == "PRINT") {
            cin >> n;
            if (n == 1) cout << box1 << "\n";
            else if (n == 2) cout << box2 << "\n";
            else if (n == 3) cout << sbox << "\n";
        } else if (cmd == "SIZE") {
            cin >> n;
            if (n == 1) cout << box1.size() << "\n";
            else if (n == 2) cout << box2.size() << "\n";
            else if (n == 3) cout << sbox.size() << "\n";
        } else if (cmd == "MERGE") {
            int moved = safeMerge(box1, box2);
            cout << "Dipindahkan: " << moved << " item\n";
        }
    }

    return 0;
}