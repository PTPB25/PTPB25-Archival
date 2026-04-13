#include "Parrot.hpp"
#include <iostream>

Parrot::Parrot(string name, int age, int vocabulary): Pet(name, age), vocabulary(vocabulary) {
    cout << "[PARROT] "<<name<<" entered knowing " << vocabulary <<" words\n";
}
Parrot::~Parrot() {
    cout << "[PARROT] "<<name<<" squawks goodbye\n";
}

void Parrot::makeSound() const {
    cout << "[SOUND] " << name << ": Squawk! I know "<< vocabulary <<" words!\n";
}

void Parrot::play() {
    happiness += 10;
    vocabulary++;
    cout << "[PLAY] "<<name<<" learns a new word! Vocabulary: "<< vocabulary <<", Happiness: "<<happiness<<"\n";
}
void Parrot::feed() {
    happiness += 3;
    cout << "[FEED] "<<name<<" eats seeds! Happiness: "<<happiness<<"\n";
}