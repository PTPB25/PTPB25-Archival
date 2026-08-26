#pragma once
#include <string>
#include "Creature.hpp"
using namespace std;

class Elf : public Creature {
protected:
    int grace;

public:
    Elf(string name, int hp, int grace);
    void describe() const override;
    int getGrace() const;
};