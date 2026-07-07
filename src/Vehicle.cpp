#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(double position,double velocity)
    :m_position(position),m_velocity(velocity),m_acceleration(0.0){
}

void Vehicle::setAcceleration(double acceleration){
    m_acceleration=acceleration;
}

void Vehicle::update(double dt){
    m_velocity=m_velocity+m_acceleration*dt;
    m_position=m_position+m_velocity*dt;
}

double Vehicle::getPosition() const{
    return m_position;
}

double Vehicle::getVelocity() const{
    return m_velocity;
}

double Vehicle::getAcceleration() const{
    return m_acceleration;
}
