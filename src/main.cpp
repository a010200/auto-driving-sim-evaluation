#include <iostream>
#include "Vehicle.h"
#include "LeadVehicle.h"
#include "Logger.h"

using namespace std;

int main(){
    Vehicle egoVehicle(0.0,15.0);
    LeadVehicle leadVehicle(30.0,15.0,3.0,-4.0);
    Logger logger("data/log.csv");

    const double dt=0.1;
    const double totalTime=6.0;

    logger.writeHeader();

    cout<<"time,ego_position,ego_speed,ego_acceleration,lead_position,lead_speed,lead_acceleration,distance"<<endl;

    for(double time=0.0;time<=totalTime;time=time+dt){
        egoVehicle.setAcceleration(0.0);

        egoVehicle.update(dt);
        leadVehicle.update(time,dt);

        double distance=leadVehicle.getPosition()-egoVehicle.getPosition();

        logger.writeData(time,
                         egoVehicle.getPosition(),
                         egoVehicle.getVelocity(),
                         egoVehicle.getAcceleration(),
                         leadVehicle.getPosition(),
                         leadVehicle.getVelocity(),
                         leadVehicle.getAcceleration(),
                         distance);

        cout<<time<<","
            <<egoVehicle.getPosition()<<","
            <<egoVehicle.getVelocity()<<","
            <<egoVehicle.getAcceleration()<<","
            <<leadVehicle.getPosition()<<","
            <<leadVehicle.getVelocity()<<","
            <<leadVehicle.getAcceleration()<<","
            <<distance<<endl;
    }

    cout<<"log saved to data/log.csv"<<endl;

    return 0;
}
