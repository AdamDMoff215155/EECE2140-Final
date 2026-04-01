#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

using namespace std;

class Vehicle {
private:
    int vehicleName;
    string color;
    bool emergency;
    double position;
    double speed;

public:
    Vehicle(int vehicleName, string color, bool emergency, double position, double speed);

//getter methods 
    int getVehicleName();
    string getColor();
    bool isEmergency();
    double getPosition();
    double getSpeed();

//setter methods
    void setPosition(double newPosition);
    void setSpeed(double newSpeed);


    void move();
    int getPriority();
    void display();
};

#endif