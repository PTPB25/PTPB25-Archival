#include <iostream>
#include "OutputFormatter.hpp"

using namespace std;

void OutputFormatter::printPullStart(const std::string& playerName, const std::string& bannerName) {
    cout << playerName << " is attempting to pull from: " << bannerName << "..." << endl;
}

void OutputFormatter::printPullSuccess(int remainingGems) {
    cout << "Pull successful! Remaining gems: " << remainingGems << endl;
}

void OutputFormatter::printPullFailed(const GachaException& e) {
    cout << "Pull failed! [Error " << e.getErrorCode() << ": " << e.getErrorType() << "]" << endl;

    if (e.getErrorCode() == 1) {
        cout << "Please top up your gems!" << endl;
    } else if (e.getErrorCode() == 2) {
        cout << "Please wait for the next banner rerun!" << endl;
    } else if (e.getErrorCode() == 3) {
        cout << "Wow! Everything is sold out." << endl;
    }
}

void OutputFormatter::printRollbackLog(int currentGems) {
    cout << "Gems safely kept. Current gems: " << currentGems << endl;
}

void OutputFormatter::printSeparator() {
    cout << "---------------------------------" << endl;
}
