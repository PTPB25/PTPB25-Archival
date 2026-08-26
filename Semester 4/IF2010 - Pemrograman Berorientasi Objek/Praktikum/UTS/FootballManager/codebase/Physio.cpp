#include "Physio.hpp"
#include "Formatter.hpp"

Physio::Physio(const std::string& name, int age, const std::string& contractEnd, int patients): ClubMember(name, age, contractEnd), Staff(name, age, contractEnd, "Sports Medicine", "Medical"),patientsThisSeason(patients) {}

void Physio::work() const {
    Formatter::log("Physio", name, "runs a recovery & injury-prevention session. Patients this season: " + std::to_string(patientsThisSeason));
}

std::string Physio::getSpecialty() const {
    return "Injury Recovery & Prevention";
}

std::string Physio::getProfile() const {
    return Formatter::makeRow("Physio", name, {
        {"Dept", department},
        {"Patients", std::to_string(patientsThisSeason)},
        {"Wage", Formatter::wage(calculateWage())}
    });
}

Physio::~Physio() {
    Formatter::log("~Physio", name, "medical records archived.");
}
