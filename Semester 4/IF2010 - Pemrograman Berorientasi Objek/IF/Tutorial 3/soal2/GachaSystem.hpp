#ifndef GACHA_SYSTEM_HPP
#define GACHA_SYSTEM_HPP

#include "Player.hpp"
#include "Banner.hpp"

class GachaSystem {
public:
    static void performPull(Player& player, Banner& banner, int pullCost, int currentDate);
};

#endif
