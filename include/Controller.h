#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller{
public:
    Controller();

    double calculateAcceleration(double distance,
                                 double egoVelocity,
                                 double leadVelocity);
    double calculateTtc(double distance,
                        double egoVelocity,
                        double leadVelocity) const;

    double getThrottle() const;
    double getBrake() const;

private:
    double m_throttle;
    double m_brake;
};

#endif
