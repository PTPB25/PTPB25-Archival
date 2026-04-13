#pragma once
#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;

class Mage : virtual public Character {
protected:
    int mana;
public:
    Mage(string characterId, string name, int hp, int level, int mana);
    ~Mage();
    void castSpell() const;
    int getMana() const;
};
