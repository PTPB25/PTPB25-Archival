#pragma once
#include <string>
#include <vector>
#include <utility>
#include <iostream>

class Formatter {
public:
    Formatter() = delete;

    // Format a double to N decimal places
    // e.g. fixed(9.9, 2) -> "9.90"
    static std::string fixed(double value, int decimals);

    // Format a wage value with $ prefix and /wk suffix
    // e.g. wage(100000.0) -> "£100000/wk"
    static std::string wage(double value);

    // Build a profile row from a label, a name, and a list of key-value pairs.
    // e.g. makeRow("Goalkeeper", "Ederson", {{"Saves","14"},{"Rating","9.90"}})
    //   -> "Goalkeeper     | Ederson | Saves: 14 | Rating: 9.90"
    static std::string makeRow(
        const std::string& label,
        const std::string& name,
        const std::vector<std::pair<std::string, std::string>>& fields
    );

    // Print a standardised action log line to stdout.
    // e.g. log("PlayerCoach", "Vincent Kompany", "plays AND coaches from the pitch.")
    //   -> [PlayerCoach] Vincent Kompany plays AND coaches from the pitch.
    static void log(
        const std::string& label,
        const std::string& name,
        const std::string& message
    );

private:
    static constexpr int LABEL_WIDTH = 15;
};
