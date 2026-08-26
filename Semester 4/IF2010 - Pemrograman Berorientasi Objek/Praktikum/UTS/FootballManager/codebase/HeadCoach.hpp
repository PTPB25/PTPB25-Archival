#pragma once
#include "Staff.hpp"

class HeadCoach : public Staff {
private:
    std::string preferredFormation;
    int winRate;

public:
    HeadCoach(const std::string& name, int age, const std::string& contractEnd, const std::string& license, const std::string& formation, int winRate);

    void work() const override;
    std::string getSpecialty() const override;
    std::string getProfile() const override;

    ~HeadCoach();
};
