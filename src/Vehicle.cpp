#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(int ID, string color, bool emergency, double position, double speed, double maxSpeed) 
{
        this -> vehicleID = ID;
        this -> color = color;
        this->emergency = emergency;
        this->position = position;
        this->speed = speed;
        this -> maxSpeed = maxSpeed;
}

void Vehicle::accelerate(int timer)
{
    speed+= 1.0 * timer;
    if(speed > maxSpeed)
    {
        speed = maxSpeed;
    }
}

void Vehicle::stop()
{
    speed = 0;
}

int Vehicle::getVehicleID() 
{ 
    return vehicleID; 
}
string Vehicle::getColor() 
{ 
    return color; 
}
bool Vehicle::isEmergency() 
{ 
    return emergency; 
}
double Vehicle::getPosition() 
{ 
    return position; 
}
double Vehicle::getSpeed() 
{ 
    return speed; 
}

void Vehicle::setPosition(double newPosition) 
{ 
    position = newPosition; 
}
void Vehicle::setSpeed(double newSpeed) 
{ 
    speed = newSpeed; 
}

void Vehicle::move(int timer) 
{
    position += speed * timer; 
}

int Vehicle::getPriority() 
{
    if (emergency) 
    {
        return 1; 
    } 
    else 
    {
        return 0;
    }
}

void Vehicle::display() 
{
    string kind;
    if (emergency) 
    {
        kind = "Emergency";
    } 
    else 
    {
        kind = "Normal";
    }
    cout << "Vehicle ID: " << vehicleID << " Type of Car: " << kind << " Color: " << color
         << " Position in Lane: " << position << " Speed: " << speed << endl;
}
