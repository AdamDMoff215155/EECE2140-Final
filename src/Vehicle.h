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
    Vehicle(int vehicleID, string color, bool emergency, double position, double speed, double maxSpeed); // constructor to create vehicle object

    int getVehicleID();
    string getColor();
    bool isEmergency();
    double getPosition();
    double getSpeed();
    void setPosition(double newPosition);
    void setSpeed(double newSpeed);
    void move(int timer);
    int getPriority(); //returns 1 for emergency vehicles and 0 for normal vehicles; used for sorting in the intersection queue
    void display(); // displays vehicle information

    void accelerate(int timer);// increases the speed by 1 tick; will not exceed max speed
    void stop(); //sets speed to 0
};

#endif