#pragma once
#include "ClubMember.hpp"
#include <string>

class Player : virtual public ClubMember
{
protected:
    std::string position;
    int stamina;
    double rating;

public:
    Player(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, double rating);

    double calculateWage() const override;
    virtual double calculateRating() const = 0;

    virtual ~Player();
};
