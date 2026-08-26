#include "Formatter.hpp"
#include <sstream>
#include <iomanip>
#include <stdexcept>

std::string Formatter::fixed(double value, int decimals) {
    if (decimals < 0) throw std::invalid_argument("decimals must be >= 0");
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(decimals) << value;
    return oss.str();
}

std::string Formatter::wage(double value) {
    return "$" + std::to_string(static_cast<int>(value)) + "/wk";
}

std::string Formatter::makeRow(const std::string& label, const std::string& name, const std::vector<std::pair<std::string, std::string>>& fields)
{
    std::string row = label;
    if (static_cast<int>(label.size()) < LABEL_WIDTH)
        row += std::string(LABEL_WIDTH - label.size(), ' ');

    row += "| " + name + " ";

    for (const auto& p : fields) {
        const std::string& key = p.first;
        const std::string& val = p.second;
        row += "| " + key + ": " + val + " ";
    }

    return row;
}

void Formatter::log(const std::string& label, const std::string& name, const std::string& message)
{
    std::cout << "[" << label << "] " << name << " " << message << "\n";
}
