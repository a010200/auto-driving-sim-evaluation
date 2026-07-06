#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle{
public:
    Vehicle(double position,double velocity);

    void setAcceleration(double acceleration);
    void update(double dt);

    double getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;

private:
    double position_;
    double velocity_;
    double acceleration_;
};

#endif
