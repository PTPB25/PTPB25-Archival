#include <iostream>
#include <string>
#include "MesinHitungNeroifa.hpp"
#include "MesinHitungException.hpp"

using namespace std;

int main() {
    MesinHitungNeroifa mesin;

    string testCases[] = {
        "3 4 +",                // 3 + 4 = 7
        "5 1 2 + 4 * + 3 -",    // (5+((1+2)*4))-3 = 14
        "+",
        "3 + 4",
        "4 0 /",
        "2 abc +",
        "3 4",
        "-3 -2 *",
        "10 2 / 3 +",
        "15 -67x -",
    };

    int n = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < n; i++) {
        cout << "Test case " << i + 1 << ": " << testCases[i] << endl;
        try {
            int hasil = mesin.hitung(testCases[i]);
            cout << "Hasil: " << hasil << endl;
        } catch (const exception& e) {
            cout << "Exception: " << e.what() << endl;
        }
        cout << "--------------------" << endl;
    }

    return 0;
}