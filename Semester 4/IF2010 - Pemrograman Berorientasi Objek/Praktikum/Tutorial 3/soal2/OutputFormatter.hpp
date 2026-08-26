#ifndef OUTPUT_FORMATTER_HPP
#define OUTPUT_FORMATTER_HPP

#include <string>
#include "GachaException.hpp"

class OutputFormatter {
public:
    static void printPullStart(const std::string& playerName, const std::string& bannerName);
    static void printPullSuccess(int remainingGems);

    static void printPullFailed(const GachaException& e);

    static void printRollbackLog(int currentGems);
    static void printSeparator();
};

#endif
