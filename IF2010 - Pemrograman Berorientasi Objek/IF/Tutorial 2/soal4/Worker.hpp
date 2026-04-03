#ifndef WORKER_HPP
#define WORKER_HPP

#include <string>
#include "Creature.hpp"

class Worker : public virtual Creature {
protected:
    int workHours;
    std::string specialSkill;

public:
    Worker();
    Worker(const std::string& name, int power, const std::string& dimension, int workHours, const std::string& specialSkill);
    virtual ~Worker();

    int getWorkHours() const;
    const std::string& getSpecialSkill() const;
};

#endif
