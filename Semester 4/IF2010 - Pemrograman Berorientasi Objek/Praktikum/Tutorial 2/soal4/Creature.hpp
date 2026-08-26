#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature {
protected:
    std::string name;
    int power;
    std::string dimension;

public:
    Creature();
    Creature(const std::string& name, int power, const std::string& dimension);
    virtual ~Creature();

    const std::string& getName() const;
    int getPower() const;
    const std::string& getDimension() const;
};

#endif
