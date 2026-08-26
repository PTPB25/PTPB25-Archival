#include "Warrior.hpp"
#include <iostream>

Warrior::Warrior(string characterId, string name, int hp, int level, int strength): Character(characterId, name, hp, level), strength(strength) {
    cout << "[CREATE] Warrior " << name << " with " << strength << " str ready\n";
}
Warrior::~Warrior() {
    cout << "[DELETE] Warrior " << name << " destroyed\n";
}
void Warrior::attack() const {
    cout << "[ATTACK] "<< name <<" attacks with "<< strength <<" strength\n";
}
int Warrior::getStrength() const {
    return strength;
}