#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
private:
    string vehicleName;
    string color;
    bool emergency;
    double position;
    double speed;
    double waitTime;

public:
    Vehicle(string vehicleName, string color, bool emergency, double position, double speed);

    string getVehicleName();
    string getColor();
    bool isEmergency();
    double getPosition();
    double getSpeed();
    void setPosition(double newPosition);
    void setSpeed(double newSpeed);
    void move(int deltaTime);
    int getPriority();
    void display();

    void accelerate(int deltaTime);
    void stop();
    void updateWaitTime(int deltaTime);
    double getWaitTime() const;
};

#endif