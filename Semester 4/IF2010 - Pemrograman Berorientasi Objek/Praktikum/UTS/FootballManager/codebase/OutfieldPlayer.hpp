#pragma once
#include "Player.hpp"

class OutfieldPlayer : public Player {
private:
    int goals;
    int assists;
    int tackles;

public:
    OutfieldPlayer(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, int goals, int assists, int tackles);

    double calculateRating() const override;
    void work() const override;
    std::string getProfile() const override;

    ~OutfieldPlayer();
};
