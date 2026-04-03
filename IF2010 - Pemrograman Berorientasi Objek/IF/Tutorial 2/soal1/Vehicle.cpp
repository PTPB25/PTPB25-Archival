#include "Vehicle.hpp"

Vehicle::Vehicle(string vehicleId, string brand, int maxSpeed)
    : vehicleId(vehicleId), brand(brand), maxSpeed(maxSpeed) {
  cout << "[CREATE] Vehicle " << vehicleId << " (" << brand << ", " << maxSpeed << " km/h) registered\n";
}

Vehicle::~Vehicle() {
  cout << "[DELETE] Vehicle " << vehicleId << " (" << brand << ") destroyed\n";
}

string Vehicle::getVehicleId() const { return vehicleId; }

string Vehicle::getSpec() const {
  return getVehicleId() + " | " + brand + " | MaxSpeed: " + to_string(maxSpeed);
}
