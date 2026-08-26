#pragma once
#include "Player.hpp"

class Goalkeeper : public Player {
private:
    int saves;
    int cleanSheets;

public:
    Goalkeeper(const std::string& name, int age, const std::string& contractEnd, int stamina, int saves, int cleanSheets);

    double calculateRating() const override;
    void work() const override;
    std::string getProfile() const override;

    ~Goalkeeper();
};
