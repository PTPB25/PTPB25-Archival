#pragma once
#include <string>

class ClubMember {
protected:
    std::string name;
    int age;
    std::string contractEnd;

public:
    ClubMember(const std::string& name, int age, const std::string& contractEnd);

    virtual std::string getProfile() const = 0;
    virtual double calculateWage() const = 0;
    virtual void work() const = 0;

    virtual ~ClubMember();
};
