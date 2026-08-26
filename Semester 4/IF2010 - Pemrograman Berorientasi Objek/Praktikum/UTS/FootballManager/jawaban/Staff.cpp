#include "Staff.hpp"
#include "Formatter.hpp"

Staff::Staff(const std::string& name, int age, const std::string& contractEnd, const std::string& license, const std::string& dept)
    : ClubMember(name, age, contractEnd), coachingLicense(license), department(dept) {}

double Staff::calculateWage() const {
    return 50000.0;
}

Staff::~Staff() {
    Formatter::log("~Staff", name, "session record freed.");
}
