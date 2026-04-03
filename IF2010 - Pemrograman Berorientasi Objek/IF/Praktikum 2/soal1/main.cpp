#include <iostream>
#include "Creature.hpp"
#include "Elf.hpp"
#include "Ranger.hpp"
#include "Maiar.hpp"
#include "Wizard.hpp"
#include "Balrog.hpp"

using namespace std;

int main() {
    Elf legolas("Legolas", 120, 95);
    Ranger aragorn("Aragorn", 110, 85, 20);
    Wizard gandalf("Gandalf", 300, 100, "Staff of the Grey Pilgrim");
    Balrog durin("Durin's Bane", 500, 150, "Flame Whip");

    Creature* c1 = &legolas;
    Creature* c2 = &aragorn;

    c1->describe();
    c2->describe();

    cout << "\nGrace Aragorn: " << aragorn.getGrace() << "\n";

    aragorn.shoot();
    cout << "Setelah Aragorn menembak:\n";
    aragorn.describe();

    cout << "\nWizard Action:\n";
    gandalf.describe();
    gandalf.cast();

    cout << "\nBalrog Action:\n";
    durin.describe();
    durin.rage();
    cout << "Power sekarang: " << durin.getPower() << "\n";

    cout << "\nData Legolas:\n";
    cout << "Name  : " << legolas.getName()  << "\n";
    cout << "HP    : " << legolas.getHp()    << "\n";
    cout << "Grace : " << legolas.getGrace() << "\n";
    return 0;
}

// EXPECTED OUTPUT:
// Elf [Legolas] | HP: 120 | Grace: 95
// Ranger [Aragorn] | HP: 110 | Grace: 85 | Arrows: 20

// Grace Aragorn: 85
// Aragorn draws an arrow (grace: 85) and fires! Arrows left: 19
// Setelah Aragorn menembak:
// Ranger [Aragorn] | HP: 110 | Grace: 85 | Arrows: 19

// Wizard Action:
// Wizard [Gandalf] | HP: 300 | Staff: Staff of the Grey Pilgrim
// Gandalf channels 100 power through Staff of the Grey Pilgrim!

// Balrog Action:
// Balrog [Durin's Bane] | HP: 500 | Power: 150 | Whip: Flame Whip
// Durin's Bane cracks Flame Whip with 150 power!
// Power sekarang: 150

// Data Legolas:
// Name  : Legolas
// HP    : 120
// Grace : 95