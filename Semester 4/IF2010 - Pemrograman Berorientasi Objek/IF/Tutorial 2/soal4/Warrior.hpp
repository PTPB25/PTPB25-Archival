#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <string>
#include "Creature.hpp"

class Warrior : public virtual Creature {
protected:
    int armor;
    std::string weapon;

public:
    Warrior();
    Warrior(const std::string& name, int power, const std::string& dimension, int armor, const std::string& weapon);
    virtual ~Warrior();

    int getArmor() const;
    const std::string& getWeapon() const;
};

#endif
