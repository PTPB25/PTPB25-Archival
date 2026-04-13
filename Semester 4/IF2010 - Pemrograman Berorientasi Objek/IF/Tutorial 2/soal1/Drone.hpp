#pragma once
#include "AirVehicle.hpp"

class Drone : public AirVehicle {
private:
  int batteryLife;

public:
  Drone(string vehicleId, string brand, int maxSpeed, int maxAltitude, int batteryLife);
  ~Drone();

  void scan(string area) const;
};
