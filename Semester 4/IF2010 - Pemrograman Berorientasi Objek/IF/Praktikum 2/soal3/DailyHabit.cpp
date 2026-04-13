#include "DailyHabit.hpp"
#include <string>

DailyHabit::DailyHabit(const std::string& name): Activity(name), streak(0) {}
    
int DailyHabit::complete() {
    streak++;
    return streak * 10;
}
std::string DailyHabit::getStatus() const {
    return "[HABIT] " + name + " - Streak: " + std::to_string(streak);
}

DailyHabit::~DailyHabit() {
    std::cout << "Menghapus DailyHabit "<< name << "\n";
}