#pragma once
#include "Staff.hpp"

class Physio : public Staff {
private:
    int patientsThisSeason;

public:
    Physio(const std::string& name, int age, const std::string& contractEnd, int patients);

    void work() const override;
    std::string getSpecialty() const override;
    std::string getProfile() const override;

    ~Physio();
};
