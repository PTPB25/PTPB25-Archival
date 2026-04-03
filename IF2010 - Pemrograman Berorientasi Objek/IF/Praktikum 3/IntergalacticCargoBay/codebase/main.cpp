#include <iostream>
#include <string>
#include <map>
#include "CargoBay.hpp"
#include "Formatter.hpp"

using namespace std;

int main() {
    map<string, CargoBay<string>*> stringBays;
    map<string, CargoBay<int>*> intBays;

    string command;
    while (cin >> command) {
        try {
            if (command == "CREATE") {
                string type, name; int cap;
                cin >> type >> name >> cap;
                if (type == "STRING") stringBays[name] = new CargoBay<string>(cap);
                else if (type == "INT") intBays[name] = new CargoBay<int>(cap);
                Formatter::printMessage("Created " + type + " bay: " + name);
            }
            else if (command == "PUSH") {
                string type, name; int dur;
                cin >> type >> name;
                if (type == "STRING") {
                    string data; cin >> data >> dur;
                    stringBays[name]->push(Item<string>(data, dur));
                }
                else if (type == "INT") {
                    int data; cin >> data >> dur;
                    intBays[name]->push(Item<int>(data, dur));
                }
                Formatter::printMessage("Pushed to " + name);
            }
            else if (command == "POP") {
                string type, name; cin >> type >> name;
                if (type == "STRING") Formatter::printItem("Popped from " + name, stringBays[name]->pop());
                else if (type == "INT") Formatter::printItem("Popped from " + name, intBays[name]->pop());
            }
            else if (command == "EXTRACT") {
                string type, name; cin >> type >> name;
                if (type == "STRING") {
                    string target; cin >> target;
                    Formatter::printItem("Extracted from " + name, stringBays[name]->extractItem(target));
                }
                else if (type == "INT") {
                    int target; cin >> target;
                    Formatter::printItem("Extracted from " + name, intBays[name]->extractItem(target));
                }
            }
            else if (command == "FORGE") {
                string type, name; cin >> type >> name;
                if (type == "STRING") {
                    string base; cin >> base;
                    stringBays[name]->forge(base);
                }
                else if (type == "INT") {
                    int base; cin >> base;
                    intBays[name]->forge(base);
                }
                Formatter::printMessage("Forge " + name + " success");
            }
            else if (command == "TRANSFER") {
                string type, src, dest; int count;
                cin >> type >> src >> dest >> count;
                if (type == "STRING") stringBays[src]->transferTo(*stringBays[dest], count);
                else if (type == "INT") intBays[src]->transferTo(*intBays[dest], count);
                Formatter::printMessage("Transfer " + src + " to " + dest + " success");
            }
        }
        catch (CargoException& e) {
            Formatter::printError(e);
        }
    }

    for (auto& pair : stringBays) delete pair.second;
    for (auto& pair : intBays) delete pair.second;

    return 0;
}
