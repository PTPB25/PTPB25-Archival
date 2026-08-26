#pragma once
#include "ClubMember.hpp"
#include <string>
#include <vector>

class Club {
private:
    std::string clubName;
    std::vector<ClubMember*> roster;

public:
    Club(std::string name);

    void addMember(ClubMember* member);
    void printSquadReport() const;
    void runTraining() const;

    ~Club();
};
