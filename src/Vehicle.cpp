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
} // constructor to create vehicle object

void Vehicle::accelerate(int timer) // increases the speed by 1 tick; will not exceed maz speed
{
    speed+= 1.0 * timer;
    if(speed > maxSpeed)
    {
        speed = maxSpeed;
    }
}

void Vehicle::stop() //sets speed to 0
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

void Vehicle::move(int timer) //updates position based on speed and time
{
    position += speed * timer; 
}

int Vehicle::getPriority() //returns 1 for emergency vehicles and 0 for normal vehicles; used for sorting in the intersection queue
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

void Vehicle::display() // displays vehicle information
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
