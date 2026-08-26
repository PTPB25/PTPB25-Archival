#include "Player.hpp"
#include "Formatter.hpp"

Player::Player(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, double rating)
    : ClubMember(name, age, contractEnd), position(position), stamina(stamina), rating(rating) {}

double Player::calculateWage() const {
    return rating * 10000.0;
}

Player::~Player() {
    Formatter::log("~Player", name, "training log freed.");
}
