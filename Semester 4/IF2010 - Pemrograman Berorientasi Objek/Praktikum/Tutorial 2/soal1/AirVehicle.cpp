#include "AirVehicle.hpp"

AirVehicle::AirVehicle(string vehicleId, string brand, int maxSpeed, int maxAltitude)
    : Vehicle(vehicleId, brand, maxSpeed), maxAltitude(maxAltitude) {
    cout << "[CREATE] AirVehicle "<< brand <<" at max altitude " << maxAltitude << "m ready\n";
}

AirVehicle::~AirVehicle() {
    cout << "[DELETE] AirVehicle " << brand << " destroyed\n";
}

void AirVehicle::fly(string destination) const {
    cout << "[FLY] " << brand << " (max " << maxAltitude << "m) flying to " << destination << "\n";
}

string AirVehicle::showSpec() const {
    return getSpec();
}

string AirVehicle::getBrandName() const {
    return brand;
}