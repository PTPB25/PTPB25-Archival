#include "Cat.hpp"
#include <iostream>

Cat::Cat(string name, int age, bool indoor): Pet(name, age), indoor(indoor) {
    if(indoor) {
        cout << "[CAT] "<<name<<" entered as indoor cat\n";
    }
    else {
        cout << "[CAT] "<<name<<" entered as outdoor cat\n";
    }
}
Cat::~Cat() {
    cout << "[CAT] "<<name<<" meows goodbye\n";
}

void Cat::makeSound() const {
    cout << "[SOUND] " << name << ": Meow!\n";
}

void Cat::play() {
    if(indoor) {
        happiness += 15;
        cout << "[PLAY] "<<name<<" plays with yarn! Happiness: "<<happiness<<"\n";
    }
    else {
        happiness += 20;
        cout << "[PLAY] "<<name<<" chases mice! Happiness: "<<happiness<<"\n";
    }
}
void Cat::feed() {
    happiness += 8;
    cout << "[FEED] "<<name<<" eats fish! Happiness: "<<happiness<<"\n";
}