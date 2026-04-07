#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
private:
    int vehicleID;
    string color;
    bool emergency;
    double position;
    double speed;
    double maxSpeed;

public:
    Vehicle(int vehicleID, string color, bool emergency, double position, double speed, double maxSpeed);

    int getVehicleID();
    string getColor();
    bool isEmergency();
    double getPosition();
    double getSpeed();
    void setPosition(double newPosition);
    void setSpeed(double newSpeed);
    void move(int timer);
    int getPriority();
    void display();

    void accelerate(int timer);
    void stop();
};

#endif