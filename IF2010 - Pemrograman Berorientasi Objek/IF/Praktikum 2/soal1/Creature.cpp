#include "Creature.hpp"
#include <iostream>

Creature::Creature(const string& name, int hp): name(name), hp(hp) {}

string Creature::getName() const { return name; }

int Creature::getHp()   const { return hp; }