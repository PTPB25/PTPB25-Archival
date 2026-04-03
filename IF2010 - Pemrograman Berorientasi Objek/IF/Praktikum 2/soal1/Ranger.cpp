#include "Ranger.hpp"
#include <iostream>

Ranger::Ranger(string name, int hp, int grace, int arrows) : Elf(name, hp, grace), arrows(arrows){}
void Ranger::describe() const {
    cout << "Ranger ["<<name<<"] | HP: "<<hp<<" | Grace: "<<grace<<" | Arrows: "<<arrows<<"\n";
}
void Ranger::shoot() {
    cout << name <<" draws an arrow (grace: "<<grace <<") and fires! Arrows left: "<<arrows-1 <<"\n";
    arrows--;
}