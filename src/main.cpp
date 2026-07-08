#include <iostream>
#include "Vehicle.h"
#include "LeadVehicle.h"
#include "Logger.h"
#include "Controller.h"

using namespace std;

int main(){
    Vehicle egoVehicle(0.0,15.0);
    LeadVehicle leadVehicle(30.0,15.0,3.0,-4.0);
    Controller controller;
    Logger logger("data/log.csv");

    const double dt=0.1;
    const double totalTime=6.0;

    logger.writeHeader();

    cout<<"time,ego_position,ego_speed,ego_acceleration,lead_position,lead_speed,lead_acceleration,distance,throttle,brake,ttc"<<endl;

    for(double time=0.0;time<=totalTime;time=time+dt){
        double currentDistance=leadVehicle.getPosition()-egoVehicle.getPosition();
        double egoAcceleration=controller.calculateAcceleration(currentDistance,
                                                                egoVehicle.getVelocity(),
                                                                leadVehicle.getVelocity());

        egoVehicle.setAcceleration(egoAcceleration);

        egoVehicle.update(dt);
        leadVehicle.update(time,dt);

        double distance=leadVehicle.getPosition()-egoVehicle.getPosition();
        double ttc=controller.calculateTtc(distance,
                                           egoVehicle.getVelocity(),
                                           leadVehicle.getVelocity());

        logger.writeData(time,
                         egoVehicle.getPosition(),
                         egoVehicle.getVelocity(),
                         egoVehicle.getAcceleration(),
                         leadVehicle.getPosition(),
                         leadVehicle.getVelocity(),
                         leadVehicle.getAcceleration(),
                         distance,
                         controller.getThrottle(),
                         controller.getBrake(),
                         ttc);//向目标文件写入数据不是控制台

        cout<<time<<","
            <<egoVehicle.getPosition()<<","
            <<egoVehicle.getVelocity()<<","
            <<egoVehicle.getAcceleration()<<","
            <<leadVehicle.getPosition()<<","
            <<leadVehicle.getVelocity()<<","
            <<leadVehicle.getAcceleration()<<","
            <<distance<<","
            <<controller.getThrottle()<<","
            <<controller.getBrake()<<","
            <<ttc<<endl;
    }//向控制台打印输出数据注意和上面logger.writeData区分
        logger.close();
    cout<<"log saved to data/log.csv"<<endl;

    return 0;
}
