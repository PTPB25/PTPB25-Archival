#pragma once
#include "Character.hpp"
#include <iostream>
#include <string>
using namespace std;

class Warrior : virtual public Character {
protected:
    int strength;
public:
    Warrior(string characterId, string name, int hp, int level, int strength);
    ~Warrior();
    void attack() const;
    int getStrength() const;
};
