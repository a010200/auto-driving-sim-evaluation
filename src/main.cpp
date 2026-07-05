#include <iostream>

#include "Vehicle.h"

int main() {
    Vehicle ego_vehicle(0.0, 0.0);

    const double dt = 0.1;
    const double total_time = 5.0;

    std::cout << "time,position,velocity,acceleration\n";

    for (double time = 0.0; time <= total_time; time = time + dt) {
        if (time < 2.0) {
            ego_vehicle.setAcceleration(1.0);
        } else {
            ego_vehicle.setAcceleration(0.0);
        }

        ego_vehicle.update(dt);

        std::cout << time << ","
                  << ego_vehicle.getPosition() << ","
                  << ego_vehicle.getVelocity() << ","
                  << ego_vehicle.getAcceleration() << "\n";
    }

    return 0;
}
