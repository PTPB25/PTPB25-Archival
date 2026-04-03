#include "MesinHitungNeroifa.hpp"
#include "MesinHitungException.hpp"

#include <stack>
#include <sstream>
#include <cctype>
using namespace std;

MesinHitungNeroifa::MesinHitungNeroifa() {}

int MesinHitungNeroifa::hitung(const string& ekspresi) const {
    stack<int> st;
    stringstream ss(ekspresi);
    string token;

    while (ss >> token) {
        // TODO:
        // Jika token adalah operator (+, -, *, /),
        // lakukan operasi terhadap dua elemen teratas stack.
        // Jika jumlah operand tidak mencukupi, lempar exception yang sesuai.

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) throw InsufficientOperandException();

            // TODO: ambil dua operand teratas dari stack
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();

            // TODO: lakukan operasi sesuai token
            // Perhatikan bahwa pembagian dengan nol harus melempar exception
            if (token == "+") {
                st.push(operand1 + operand2);
            }
            else if (token == "-") {
                st.push(operand1 - operand2);
            }
            else if (token == "*") {
                st.push(operand1 * operand2);
            }
            else if (token == "/") {
                if (operand2 == 0) throw DivisionByZeroException();
                st.push(operand1 / operand2);
            }
        } else {
            // TODO:
            // Anggap token sebagai kandidat bilangan bulat.
            // Cek apakah token valid:
            // - boleh berupa bilangan negatif
            // - selain itu semua karakter harus digit
            bool valid = true;
            int startIdx = 0;            

            if (token.size() >= 1 && token[0] == '-') {
                startIdx++;
            }

            for (;startIdx < token.size() && valid; startIdx++) {
                if (token[startIdx] < '0' || token[startIdx] > '9') valid = false;
            }


            if (!valid) {
                throw InvalidTokenException(token);
            }

            st.push(atoi(token.c_str()));
        }
    }

    // TODO:
    // Setelah semua token diproses, stack harus berisi tepat satu elemen.
    // Jika tidak, lempar exception yang sesuai.
    if (st.size() != 1) throw InvalidExpressionException();

    // TODO: kembalikan hasil akhir
    return st.top();
}