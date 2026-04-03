#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
private:
    std::string name;
    int gems;

public:
    Player(std::string name, int initialGems);

    std::string getName() const;
    int getGems() const;

    void addGems(int amount);
    void deductGems(int amount);
};

#endif
