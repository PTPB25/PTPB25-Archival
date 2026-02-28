#include "Paper.hpp"

using namespace std;

Paper::Paper(char c) {
    name = c;
    n_fold = 0;
    cout << "ctor " << c << endl;
}

Paper::Paper(const Paper& p) {
    cout << "cctor " << p.name << endl;
    name = p.name;
    n_fold = p.n_fold;
}

Paper::~Paper() {
    cout << "dtor " << name << endl;
}

void Paper::setName(char c) {
    cout << "setName " << name << " => " << c << endl;
    name = c;
}

void Paper::fold() {
    n_fold += 1;    
    cout << "fold " << name << "(" << n_fold << ")" << endl;
}

void Paper::glue() {
    cout << "glue " << name << endl;
    fold();
}