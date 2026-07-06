#include "Vehicle.h"

Vehicle::Vehicle(double position,double velocity)
    : position_(position),velocity_(velocity),acceleration_(0.0){
}

void Vehicle::setAcceleration(double acceleration){
    acceleration_=acceleration;
}

void Vehicle::update(double dt){
    velocity_=velocity_+acceleration_*dt;
    position_=position_+velocity_*dt;
}

double Vehicle::getPosition() const{
    return position_;
}

double Vehicle::getVelocity() const{
    return velocity_;
}

double Vehicle::getAcceleration() const{
    return acceleration_;
}
