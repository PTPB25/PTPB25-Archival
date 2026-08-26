#ifndef NIMON_HPP
#define NIMON_HPP

#include <string>
#include "Worker.hpp"
#include "Warrior.hpp"

class Nimon : public Worker, public Warrior {
private:
    int loyalty;

public:
    Nimon();
    Nimon(const std::string& name, int power, const std::string& dimension,
          int workHours, const std::string& specialSkill,
          int armor, const std::string& weapon, int loyalty);
    ~Nimon() override;

    int getLoyalty() const;
    std::string getProfileLine() const;
};

#endif
