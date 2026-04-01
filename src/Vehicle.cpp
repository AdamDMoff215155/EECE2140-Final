#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(int vehicleName, string color, bool emergency, double position, double speed) {
        this->vehicleName = vehicleName;
        this->color = color;
        this->emergency = emergency;
        this->position = position;
        this->speed = speed;
}


int Vehicle::getVehicleName() { 
    return vehicleName; 
}
string Vehicle::getColor() { 
    return color; 
}
bool Vehicle::isEmergency() { 
    return emergency; 
}
double Vehicle::getPosition() { 
    return position; 
}
double Vehicle::getSpeed() { 
    return speed; 
}


void Vehicle::setPosition(double newPosition) { 
    position = newPosition; 
}
void Vehicle::setSpeed(double newSpeed) { 
    speed = newSpeed; 
}


void Vehicle::move() {
    position += speed; 
}

int Vehicle::getPriority() {
    if (emergency) {
        return 1; 
    } else {
        return 0;
    }
}

void Vehicle::display() {
    string kind;
    if (emergency) {
        kind = "Emergency";
    } 
    else {
        kind = "Normal";
    }
    cout << "Vehicle " << vehicleName
         << "Type of Car: " << kind
         << "Color: " << color
         << "Position in Lane: " << position
         << "Speed: " << speed << endl;
}
