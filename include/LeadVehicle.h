#ifndef LEADVEHICLE_H
#define LEADVEHICLE_H

class LeadVehicle{
public:
    LeadVehicle(double position,
                double velocity,
                double brakeStartTime,
                double brakeAcceleration);

    void update(double time,double dt);

    double getPosition() const;
    double getVelocity() const;
    double getAcceleration() const;

private:
    double m_position;
    double m_velocity;
    double m_acceleration;
    double m_brakeStartTime;
    double m_brakeAcceleration;
};

#endif
