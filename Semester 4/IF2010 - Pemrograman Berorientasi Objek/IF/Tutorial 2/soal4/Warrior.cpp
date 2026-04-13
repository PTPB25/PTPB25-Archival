#include "Warrior.hpp"

Warrior::Warrior() : Creature(), armor(0), weapon("none") {}

Warrior::Warrior(const std::string& name, int power, const std::string& dimension,
                     int armor, const std::string& weapon)
    : Creature(name, power, dimension), armor(armor), weapon(weapon) {}

Warrior::~Warrior() = default;

int Warrior::getArmor() const {
    return armor;
}

const std::string& Warrior::getWeapon() const {
    return weapon;
}
