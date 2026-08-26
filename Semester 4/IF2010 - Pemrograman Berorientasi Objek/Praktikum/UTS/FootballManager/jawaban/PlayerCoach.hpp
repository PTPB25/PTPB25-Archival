#pragma once
#include "Player.hpp"
#include "Staff.hpp"

class PlayerCoach : public Player, public Staff
{
private:
    int yearsAsPlayer;
    bool isCurrentlyPlaying;

public:
    PlayerCoach(const std::string& name, int age, const std::string& contractEnd, const std::string& position, int stamina, double rating, const std::string& license, int yearsAsPlayer, bool isCurrentlyPlaying);

    void work() const override;
    double calculateRating() const override;
    std::string getSpecialty() const override;
    double calculateWage() const override;
    std::string getProfile() const override;

    ~PlayerCoach();
};
