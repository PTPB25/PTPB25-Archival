#pragma once
#include "WaterVehicle.hpp"

class Submarine : public WaterVehicle {
private:
  int maxDepth;

public:
  Submarine(string vehicleId, string brand, int maxSpeed, int displacement, int maxDepth);
  ~Submarine();

  void dive(int depth) const;
};
