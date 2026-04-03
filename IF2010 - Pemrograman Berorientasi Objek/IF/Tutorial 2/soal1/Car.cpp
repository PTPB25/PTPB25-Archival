#include "Car.hpp"

Car::Car(string vehicleId, string brand, int maxSpeed, int numWheels, string carType)
    : LandVehicle(vehicleId, brand, maxSpeed, numWheels), carType(carType) {
  cout << "[CREATE] Car " << brand << " type " << carType << " ready\n";
}

Car::~Car() { cout << "[DELETE] Car " << brand << " destroyed\n"; }

void Car::race() const {
  cout << "[RACE] " << brand << " " << carType << " racing at max " << maxSpeed << " km/h\n";
}
