#pragma once
#include "Vehicle.hpp"

class LandVehicle : public Vehicle {
    private:
        string vehicleId;
        int numWheels;
    public:
        void drive(string destination) const;
        LandVehicle(string vehicleId, string brand, int maxSpeed, int numWheels);
        ~LandVehicle();
};
