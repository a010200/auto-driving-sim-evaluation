#include "LeadVehicle.h"

using namespace std;

LeadVehicle::LeadVehicle(double position,
                         double velocity,
                         double brakeStartTime,
                         double brakeAcceleration){
    m_position=position;
    m_velocity=velocity;
    m_acceleration=0.0;
    m_brakeStartTime=brakeStartTime;
    m_brakeAcceleration=brakeAcceleration;
}

void LeadVehicle::update(double time,double dt){
    if(time>=m_brakeStartTime&&m_velocity>0.0){
        m_acceleration=m_brakeAcceleration;
    }else{
        m_acceleration=0.0;
    }

    m_velocity=m_velocity+m_acceleration*dt;

    if(m_velocity<0.0){
        m_velocity=0.0;
        m_acceleration=0.0;
    }

    m_position=m_position+m_velocity*dt;
}

double LeadVehicle::getPosition() const{
    return m_position;
}

double LeadVehicle::getVelocity() const{
    return m_velocity;
}

double LeadVehicle::getAcceleration() const{
    return m_acceleration;
}
