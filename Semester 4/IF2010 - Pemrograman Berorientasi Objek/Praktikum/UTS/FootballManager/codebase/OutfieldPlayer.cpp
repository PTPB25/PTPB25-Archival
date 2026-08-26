#include "OutfieldPlayer.hpp"
#include "Formatter.hpp"

OutfieldPlayer::OutfieldPlayer(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, int goals, int assists, int tackles)
    : ClubMember(name, age, contractEnd), Player(name, age, contractEnd, position, stamina, 0.0), goals(goals), assists(assists), tackles(tackles)
{
    rating = calculateRating();
}

double OutfieldPlayer::calculateRating() const {
    double r = goals * 0.5 + assists * 0.3 + tackles * 0.1;
    return r > 10.0 ? 10.0 : r;
}

void OutfieldPlayer::work() const {
    Formatter::log("OutfieldPlayer", name, "(" + position + ") runs, dribbles, and shoots. Stamina: " + std::to_string(stamina));
}

std::string OutfieldPlayer::getProfile() const {
    return Formatter::makeRow("OutfieldPlayer", name, {
        {"Pos",     position},
        {"Goals",   std::to_string(goals)},
        {"Assists", std::to_string(assists)},
        {"Rating",  Formatter::fixed(calculateRating(), 2)},
        {"Wage",    Formatter::wage(calculateWage())}
    });
}

OutfieldPlayer::~OutfieldPlayer() {
    Formatter::log("~OutfieldPlayer", name, "stats record cleared.");
}
