#include "Creature.hpp"

Creature::Creature() : name("Unknown"), power(0), dimension("Nowhere") {}

Creature::Creature(const std::string& name, int power, const std::string& dimension)
    : name(name), power(power), dimension(dimension) {}

Creature::~Creature() = default;

const std::string& Creature::getName() const {
    return name;
}

int Creature::getPower() const {
    return power;
}

const std::string& Creature::getDimension() const {
    return dimension;
}
