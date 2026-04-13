#include "Balrog.hpp"
#include <iostream>

Balrog::Balrog(string name, int hp, int power, string whipName): Maiar(name, hp, power), whipName(whipName) {}
void Balrog::describe() const {
    cout << "Balrog ["<<name<<"] | HP: "<<hp<<" | Power: "<<getPower()<<" | Whip: "<<whipName<<"\n";
}
void Balrog::rage() const {
    cout <<name<<" cracks "<<whipName<<" with "<<getPower()<<" power!\n";
}