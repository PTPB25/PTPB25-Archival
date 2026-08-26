#include "Club.hpp"
#include "Player.hpp"
#include "Staff.hpp"
#include <iostream>

Club::Club(std::string name)
    : clubName(name) {}

void Club::addMember(ClubMember* member) {
    roster.push_back(member);
}

void Club::printSquadReport() const {
    std::cout << "\n======================================\n";
    std::cout << "  " << clubName << " - Squad Report\n";
    std::cout << "======================================\n";
    for (const ClubMember* member : roster) {
        std::cout << member->getProfile() << "\n";
    }
}

void Club::runTraining() const {
    std::cout << "\n--- Match Day Actions ---\n";
    for (const ClubMember* member : roster) {
        member->work();
    }
}

Club::~Club() {
    std::cout << "\n--- Releasing Club Roster ---\n";
    for (ClubMember* member : roster) {
        delete member;
    }
    roster.clear();
}
