#include "PlayerCoach.hpp"
#include "Formatter.hpp"

PlayerCoach::PlayerCoach(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, double rating, const std::string& license, int yearsAsPlayer, bool isCurrentlyPlaying)
    : ClubMember(name, age, contractEnd),
      Player(name, age, contractEnd, position, stamina, rating),
      Staff(name, age, contractEnd, license, "Coaching"),
      yearsAsPlayer(yearsAsPlayer),
      isCurrentlyPlaying(isCurrentlyPlaying) {}

void PlayerCoach::work() const {
    if (isCurrentlyPlaying) {
        Formatter::log("PlayerCoach", name, "plays AND coaches from the pitch.");
    } else {
        Formatter::log("PlayerCoach", name, "coaches from the touchline.");
    }
}

double PlayerCoach::calculateRating() const {
    return rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0;
}

std::string PlayerCoach::getSpecialty() const {
    return "Playing + Coaching (Player-Coach, " + std::to_string(yearsAsPlayer) + " yrs exp)";
}

double PlayerCoach::calculateWage() const {
    return Player::calculateWage() + Staff::calculateWage();
}

std::string PlayerCoach::getProfile() const {
    return Formatter::makeRow("PlayerCoach", name, {
        {"Pos", position},
        {"Lic", coachingLicense},
        {"Specialty", getSpecialty()},
        {"Wage", Formatter::wage(calculateWage())}
    });
}

PlayerCoach::~PlayerCoach() {
    Formatter::log("~PlayerCoach", name, "dual-role contract terminated.");
}
