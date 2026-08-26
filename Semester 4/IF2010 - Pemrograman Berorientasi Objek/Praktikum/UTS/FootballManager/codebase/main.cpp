#include "ClubMember.hpp"
#include "OutfieldPlayer.hpp"
#include "Goalkeeper.hpp"
#include "HeadCoach.hpp"
#include "Physio.hpp"
#include "PlayerCoach.hpp"
#include "Club.hpp"

int main() {
    Club city("Manchester City FC");

    city.addMember(new OutfieldPlayer("Erling Haaland", 23, "2027-06-30", "ST", 92, 27,  5, 10));
    city.addMember(new OutfieldPlayer("Kevin De Bruyne", 32, "2025-06-30", "CM", 78,  8, 20, 35));
    city.addMember(new OutfieldPlayer("Ruben Dias", 26, "2027-06-30", "CB", 88, 2, 3, 80));
    city.addMember(new Goalkeeper("Ederson", 30, "2026-06-30", 90, 14, 12));
    city.addMember(new HeadCoach("Pep Guardiola", 52, "2025-06-30", "UEFA Pro", "4-3-3", 72));
    city.addMember(new Physio("Dr. Sarah Collins", 41, "2026-06-30", 34));
    city.addMember(new PlayerCoach("Vincent Kompany", 37, "2025-06-30", "CB", 60, 6.8, "UEFA Pro", 14, true));

    city.printSquadReport();
    city.runTraining();

    return 0;
}
