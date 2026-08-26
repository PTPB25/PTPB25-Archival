#include "PlayerCoach.hpp"
#include "Formatter.hpp"

PlayerCoach::PlayerCoach()
    // TODO: Constructor
{
}

void PlayerCoach::work() {
    // TODO: log menggunakan Formatter::log, dengan pesan yang berbeda tergantung isCurrentlyPlaying
    // Jika isCurrentlyPlaying -> Output: "[PlayerCoach] Name plays AND coaches from the pitch."
    // else -> Output: "[PlayerCoach] Name coaches from the touchline."
}

double PlayerCoach::calculateRating() {
    // TODO: return rating dengan rumus: rating * 0.7 + (yearsAsPlayer / 20.0) * 3.0
}

std::string PlayerCoach::getSpecialty() {
    // TODO: return "Playing + Coaching (Player-Coach, yearsAsPlayer yrs exp)"
}

double PlayerCoach::calculateWage() {
    // TODO: Jumlahkan calculateWage dari kelas Player and Staff
}

std::string PlayerCoach::getProfile() {
    // TODO: gunakan Formatter::makeRow dengan label "PlayerCoach" dan fields: Pos, Lic, Specialty, Wage
}

PlayerCoach::~PlayerCoach() {
    // TODO: log destruction menggunakan Formatter::log
}
