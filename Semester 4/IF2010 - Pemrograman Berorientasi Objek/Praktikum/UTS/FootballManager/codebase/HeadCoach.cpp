#include "HeadCoach.hpp"
#include "Formatter.hpp"

HeadCoach::HeadCoach(const std::string& name, int age, const std::string& contractEnd, const std::string& license, const std::string& formation, int winRate): ClubMember(name, age, contractEnd), Staff(name, age, contractEnd, license, "Coaching"), preferredFormation(formation), winRate(winRate) {}

void HeadCoach::work() const {
    Formatter::log("HeadCoach", name, "runs a tactical session. Formation: " + preferredFormation);
}

std::string HeadCoach::getSpecialty() const {
    return "Tactics & Formation (" + preferredFormation + ")";
}

std::string HeadCoach::getProfile() const {
    return Formatter::makeRow("HeadCoach", name, {
        {"Lic",       coachingLicense},
        {"Formation", preferredFormation},
        {"Win rate",  std::to_string(winRate) + "%"},
        {"Wage",      Formatter::wage(calculateWage())}
    });
}

HeadCoach::~HeadCoach() {
    Formatter::log("~HeadCoach", name, "tactics board wiped.");
}
