#include "Drone.hpp"

Drone::Drone(string vehicleId, string brand, int maxSpeed, int maxAltitude, int batteryLife)
    : AirVehicle(vehicleId, brand, maxSpeed, maxAltitude), batteryLife(batteryLife) {
  cout << "[CREATE] Drone " << getBrandName() << " with " << batteryLife << "min battery ready\n";
}

Drone::~Drone() {
  cout << "[DELETE] Drone " << getBrandName() << " destroyed\n";
}

void Drone::scan(string area) const {
  cout << "[SCAN] " << getBrandName() << " scanning " << area << " for " << batteryLife << " minutes\n";
}
