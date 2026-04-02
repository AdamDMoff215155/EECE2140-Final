#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string Name, string color, bool emergency, double position, double speed) 
{
        this -> vehicleName = Name;
        this -> color = color;
        this->emergency = emergency;
        this->position = position;
        this->speed = speed;
        this -> waitTime = 0.0;
}

void Vehicle::accelerate(int deltaTime)
{
    speed+= 1.0 * deltaTime;
}

void Vehicle::stop()
{
    speed = 0;
}

void Vehicle::updateWaitTime(int deltaTime)
{
    if(speed == 0)
    {
        waitTime +=deltaTime;
    }
}

double Vehicle::getWaitTime() const
{
    return waitTime;
}

string Vehicle::getVehicleName() 
{ 
    return vehicleName; 
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


void Vehicle::move(int deltaTime) 
{
    position += speed * deltaTime; 
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
    cout << "Vehicle: " << vehicleName << " Type of Car: " << kind << " Color: " << color
         << " Position in Lane: " << position << " Speed: " << speed << endl;
}
