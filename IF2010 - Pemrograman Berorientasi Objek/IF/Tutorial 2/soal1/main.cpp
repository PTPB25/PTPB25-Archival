#include "Car.hpp"
#include "Drone.hpp"
#include "Submarine.hpp"

int main() {
  cout << "\n--- Land Vehicle: Car ---\n";
  Car car("V001", "Toyota", 180, 4, "Sedan");
  car.drive("Jakarta");
  car.race();
  cout << "[SPEC] " << car.getSpec() << "\n";

  cout << "\n--- Water Vehicle: Submarine ---\n";
  Submarine sub("V002", "Krakatau", 40, 5000, 300);
  sub.sail("Selat Malaka");
  sub.dive(200);
  cout << "[SPEC] " << sub.showSpec() << "\n";

  cout << "\n--- Air Vehicle: Drone ---\n";
  Drone drone("V003", "DJI", 120, 5000, 30);
  drone.fly("Gunung Bromo");
  drone.scan("Kawah Ijen");
  cout << "[SPEC] " << drone.showSpec() << "\n";

  cout << "\n--- Cleanup ---\n";

  return 0;
}
