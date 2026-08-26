#include "Nimon.hpp"

Nimon::Nimon() : Worker(), Warrior(), loyalty(0) {}

Nimon::Nimon(const std::string& name, int power, const std::string& dimension,
             int workHours, const std::string& specialSkill,
             int armor, const std::string& weapon, int loyalty)
    : Worker(name, power, dimension, workHours, specialSkill),
      Warrior(name, power, dimension, armor, weapon),
      Creature(name, power, dimension),
      loyalty(loyalty) {}

Nimon::~Nimon() = default;

int Nimon::getLoyalty() const {
    return loyalty;
}

std::string Nimon::getProfileLine() const {
    return name + " | PWR " + std::to_string(power) +
           " | DIM " + dimension +
           " | WORK " + std::to_string(getWorkHours()) + "h-" + getSpecialSkill() +
           " | DEF " + std::to_string(getArmor()) + "-" + getWeapon() +
           " | LOY " + std::to_string(getLoyalty());
}
