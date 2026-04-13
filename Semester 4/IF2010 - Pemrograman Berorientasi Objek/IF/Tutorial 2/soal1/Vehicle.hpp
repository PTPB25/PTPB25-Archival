#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
  string vehicleId;

protected:
  string brand;
  int maxSpeed;

public:
  Vehicle(string vehicleId, string brand, int maxSpeed);
  ~Vehicle();

  string getVehicleId() const;
  string getSpec() const;
};
