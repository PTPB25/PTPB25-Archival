#include <iostream>
#include <string>
#include "TaskManager.hpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    TaskManager manager;

    while (q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            string id, title;
            int priority, duration;
            cin >> id >> title >> priority >> duration;
            if (manager.find(id) == nullptr) {
                manager.add(id, title, priority, duration);
            } else {
                manager.update(id, title, priority, duration);
            }
            cout << "OK\n";
        } else if (cmd == 2) {
            string id;
            cin >> id;
            cout << (manager.remove(id) ? "DELETED\n" : "NOT FOUND\n");
        } else if (cmd == 3) {
            string id;
            cin >> id;
            const Task* task = manager.find(id);
            if (task == nullptr) {
                cout << "NOT FOUND\n";
            } else {
                cout << task->getId() << "|" << task->getTitle() << "|" << task->getPriority() << "|" << task->getDuration() << "\n";
            }
        } else if (cmd == 4) {
            manager.sort();
            cout << "SORTED\n";
        } else if (cmd == 5) {
            int minPriority;
            cin >> minPriority;
            cout << manager.totalDuration(minPriority) << "\n";
        } else if (cmd == 6) {
            string keyword;
            cin >> keyword;
            manager.print(keyword);
            cout << "END\n";
        } else if (cmd == 7) {
            manager.print();
            cout << "END\n";
        }
    }

    return 0;
}