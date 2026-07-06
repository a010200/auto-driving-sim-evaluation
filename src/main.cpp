#include <iostream>
#include "Vehicle.h"

using namespace std;

int main(){
    Vehicle egoVehicle(0.0,0.0);

    const double dt=0.1;
    const double totalTime=5.0;

    cout<<"time,position,velocity,acceleration"<<endl;

    for(double time=0.0;time<=totalTime;time=time+dt){
        if(time<2.0){
            egoVehicle.setAcceleration(1.0);
        }else{
            egoVehicle.setAcceleration(0.0);
        }

        egoVehicle.update(dt);

        cout<<time<<","
            <<egoVehicle.getPosition()<<","
            <<egoVehicle.getVelocity()<<","
            <<egoVehicle.getAcceleration()<<endl;
    }

    return 0;
}
