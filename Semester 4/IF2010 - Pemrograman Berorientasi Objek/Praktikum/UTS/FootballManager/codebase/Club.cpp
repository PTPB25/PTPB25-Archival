#include "Club.hpp"
#include "Player.hpp"
#include "Staff.hpp"
#include <iostream>

Club::Club(std::string name)
    // TODO: constructor
{
}

void Club::addMember(ClubMember* member) {
    // TODO: push member ke roster
}

void Club::printSquadReport() const {
    std::cout << "\n======================================\n";
    std::cout << "  " << clubName << " - Squad Report\n";
    std::cout << "======================================\n";
    // TODO: panggil getProfile() dari setiap member
}

void Club::runTraining() const {
    std::cout << "\n--- Match Day Actions ---\n";
    // TODO: panggil work() dari setiap member
}

Club::~Club() {
    std::cout << "\n--- Releasing Club Roster ---\n";
    // TODO: delete semua ClubMember* di roster
}
