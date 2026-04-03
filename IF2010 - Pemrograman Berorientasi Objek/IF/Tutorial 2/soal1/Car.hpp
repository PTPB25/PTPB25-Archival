#pragma once
#include "LandVehicle.hpp"

class Car : public LandVehicle {
private:
  string carType;

public:
  Car(string vehicleId, string brand, int maxSpeed, int numWheels, string carType);
  ~Car();

  void race() const;
};
