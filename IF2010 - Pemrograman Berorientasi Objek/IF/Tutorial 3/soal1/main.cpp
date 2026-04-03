#include <iostream>
#include <string>
#include "Box.hpp"
using namespace std;

int main() {
    Box<int> boxInt(10);
    Box<string> boxStr("Hello");
    Box<int> boxDefault;
    
    boxDefault.setValue(5);
    boxDefault.printValue();

    boxInt.printValue();
    boxStr.printValue();

    boxInt.setValue(25);
    boxStr.setValue("World");

    cout << boxInt.getValue() << endl;
    cout << boxStr.getValue() << endl;

    cout << getMax(3, 7) << endl;
    cout << getMax(5.1, 2.5) << endl;

    return 0;
}