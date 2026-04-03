#include "Elf.hpp"
#include <iostream>


Elf::Elf(string name, int hp, int grace): Creature(name, hp), grace(grace) {

};
void Elf::describe() const {
    cout << "Elf ["<< name << "] | HP: " << hp <<" | Grace: " << grace << "\n";
}

int Elf::getGrace() const {
    return grace;
}