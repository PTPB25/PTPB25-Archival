#pragma once
#include "Vehicle.hpp"

class WaterVehicle : protected Vehicle {
    private:
        int displacement;
    public:
        WaterVehicle(string vehicleId, string brand, int maxSpeed, int displacement);
        ~WaterVehicle();
        void sail(string destination) const;
        string showSpec() const;
};
