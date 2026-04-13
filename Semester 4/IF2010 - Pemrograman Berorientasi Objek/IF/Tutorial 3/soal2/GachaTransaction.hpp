#ifndef GACHA_TRANSACTION_HPP
#define GACHA_TRANSACTION_HPP

#include "Player.hpp"

class GachaTransaction {
private:
    Player& player;
    int cost;
    bool isCommitted;

public:
    GachaTransaction(Player& p, int cost);
    ~GachaTransaction();

    void commit();
};

#endif
