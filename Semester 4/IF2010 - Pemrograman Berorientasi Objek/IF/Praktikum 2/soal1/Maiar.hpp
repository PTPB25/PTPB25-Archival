#pragma once
#include "Creature.hpp"
#include <string>

class Maiar : protected Creature {
private:
    int power;
protected:
    Maiar(string name, int hp, int power);
public:
    void describe() const override;
    int getPower() const;
};
