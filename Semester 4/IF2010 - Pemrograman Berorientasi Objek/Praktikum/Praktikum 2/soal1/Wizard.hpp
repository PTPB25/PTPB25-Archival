#pragma once
#include <string>
#include "Maiar.hpp"
using namespace std;

class Wizard : private Maiar {
private:
    string staffName;

public:
    Wizard(string name, int hp, int power, string staffName);
    void describe() const override;
    void cast() const;
};