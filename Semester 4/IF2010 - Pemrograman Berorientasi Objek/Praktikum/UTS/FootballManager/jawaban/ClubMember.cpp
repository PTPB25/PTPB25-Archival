#include "ClubMember.hpp"
#include "Formatter.hpp"
#include <iostream>

ClubMember::ClubMember(const std::string& name, int age, const std::string& contractEnd)
    : name(name), age(age), contractEnd(contractEnd) {}

ClubMember::~ClubMember() {
    Formatter::log("~ClubMember", name, "contract record cleared.");
}
