#include <iostream>
#include <vector>
#include "Nimon.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<Nimon> army;
    int totalPower = 0;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int power;
        std::string dimension;
        int workHours;
        std::string specialSkill;
        int armor;
        std::string weapon;
        int loyalty;

        std::cin >> name >> power >> dimension >> workHours >> specialSkill >> armor >> weapon >> loyalty;

        Nimon candidate(name, power, dimension, workHours, specialSkill, armor, weapon, loyalty);
        Creature* asCreature = &candidate;
        if (asCreature != nullptr) {
            army.push_back(candidate);
            totalPower += power;
        }
    }

    std::cout << "=== DIMENSION RECRUITMENT REPORT ===\n";
    for (int i = 0; i < static_cast<int>(army.size()); ++i) {
        std::cout << "Nimon#" << (i + 1) << " " << army[i].getProfileLine() << "\n";
    }

    std::cout << "TOTAL_NIMON " << army.size() << "\n";
    std::cout << "TOTAL_POWER " << totalPower << "\n";

    return 0;
}