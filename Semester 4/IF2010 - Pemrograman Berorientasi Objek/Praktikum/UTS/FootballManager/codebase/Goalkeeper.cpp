#include "Goalkeeper.hpp"
#include "Formatter.hpp"
#include <iostream>

Goalkeeper::Goalkeeper(const std::string& name, int age, const std::string& contractEnd, int stamina, int saves, int cleanSheets): ClubMember(name, age, contractEnd), Player(name, age, contractEnd, "GK", stamina, 0.0), saves(saves), cleanSheets(cleanSheets)
{
    rating = calculateRating();
}

double Goalkeeper::calculateRating() const {
    double r = saves * 0.3 + cleanSheets * 1.0;
    return r > 10.0 ? 10.0 : r;
}

void Goalkeeper::work() const {
    Formatter::log("Goalkeeper", name, "dives and catches. Saves: " + std::to_string(saves));
}

std::string Goalkeeper::getProfile() const {
    return Formatter::makeRow("Goalkeeper", name, {
        {"Saves", std::to_string(saves)},
        {"Clean sheets", std::to_string(cleanSheets)},
        {"Rating", Formatter::fixed(calculateRating(), 2)},
        {"Wage", Formatter::wage(calculateWage())}
    });
}

Goalkeeper::~Goalkeeper() {
    Formatter::log("~Goalkeeper", name, "glove inventory cleared.");
}
