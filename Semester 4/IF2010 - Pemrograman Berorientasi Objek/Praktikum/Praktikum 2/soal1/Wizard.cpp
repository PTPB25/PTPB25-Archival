#include "Wizard.hpp"
#include <iostream>

Wizard::Wizard(string name, int hp, int power, string staffName): Maiar(name, hp, power), staffName(staffName) {}
void Wizard::describe() const {
    cout << "Wizard ["<< name <<"] | HP: "<< hp <<" | Staff: "<< staffName <<"\n";
}
void Wizard::cast() const {
    cout << name <<" channels "<< getPower() <<" power through "<< staffName <<"!\n";
}