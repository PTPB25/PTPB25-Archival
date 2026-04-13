#include "Worker.hpp"

Worker::Worker() : Creature(), workHours(0), specialSkill("none") {}

Worker::Worker(const std::string& name, int power, const std::string& dimension,
               int workHours, const std::string& specialSkill)
    : Creature(name, power, dimension), workHours(workHours), specialSkill(specialSkill) {}

Worker::~Worker() = default;

int Worker::getWorkHours() const {
    return workHours;
}

const std::string& Worker::getSpecialSkill() const {
    return specialSkill;
}
