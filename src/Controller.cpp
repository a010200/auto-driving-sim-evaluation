#include "Controller.h"

using namespace std;

Controller::Controller(){
    m_throttle=0.0;
    m_brake=0.0;
}

double Controller::calculateAcceleration(double distance,
                                         double egoVelocity,
                                         double leadVelocity){
    double ttc=calculateTtc(distance,egoVelocity,leadVelocity);

    m_throttle=0.0;
    m_brake=0.0;

    if(distance<10.0||ttc<2.0){
        m_brake=0.8;
        return -3.0;
    }

    if(distance<20.0||ttc<4.0){
        m_brake=0.3;
        return -1.5;
    }

    if(distance>35.0){
        m_throttle=0.2;
        return 0.5;
    }

    return 0.0;
}

double Controller::calculateTtc(double distance,
                                double egoVelocity,
                                double leadVelocity) const{
    double relativeVelocity=egoVelocity-leadVelocity;

    if(relativeVelocity<=0.0){
        return 999.0;
    }

    return distance/relativeVelocity;
}

double Controller::getThrottle() const{
    return m_throttle;
}

double Controller::getBrake() const{
    return m_brake;
}
