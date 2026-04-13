#include "Submarine.hpp"

Submarine::Submarine(string vehicleId, string brand, int maxSpeed, int displacement, int maxDepth)
    : WaterVehicle(vehicleId, brand, maxSpeed, displacement), maxDepth(maxDepth) {
  cout << "[CREATE] Submarine " << brand << " max depth " << maxDepth << "m ready\n";
}

Submarine::~Submarine() {
  cout << "[DELETE] Submarine " << brand << " destroyed\n";
}

void Submarine::dive(int depth) const {
  cout << "[DIVE] " << brand << " diving to " << depth << "m (max: " << maxDepth << "m)\n";
}
