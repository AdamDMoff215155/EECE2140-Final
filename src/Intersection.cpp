#include "Intersection.h"
#include <iostream>
#include<string>

Intersection::Intersection():  //establsihes light and lane objects
    light1(10, 2, 12),        
    light2(10, 2, 12),     
    lane1(&light1, 10.0f), 
    lane2(&light2, 10.0f)
{
    light2.forceRed();
}

void Intersection::update(int timer) // updates intersection each tick; checks for emergency vehicles in each lane and updates lights accordingly; also updates lanes to move vehicles and update processed counts
{
    bool emergency1 = !lane1.isEmpty() && lane1.getFrontVehicle().isEmergency(); // check if front vehicle in lane 1 is an emergency vehicle; if lane is empty, returns false to avoid errors
    bool emergency2 = !lane2.isEmpty() && lane2.getFrontVehicle().isEmergency(); // check if front vehicle in lane 2 is an emergency vehicle; if lane is empty, returns false to avoid errors

    light1.update(emergency1);
    light2.update(emergency2);

    lane1.update(timer);
    lane2.update(timer);
}

void Intersection::vehicleToLane1(const Vehicle& v)
{
    lane1.addVehicle(v);
}

void Intersection::vehicleToLane2(const Vehicle& v)
{
    lane2.addVehicle(v);
}

int Intersection::getQueueLength1() const
{
    return lane1.getQueueLength();
}

int Intersection::getQueueLength2() const
{
    return lane2.getQueueLength();
}

string Intersection::getLight1State() const // return light state as string for terminal output
{
    return light1.getStateAsString();
}

string Intersection::getLight2State() const // return light state as string for terminal output
{
    return light2.getStateAsString();
}

int Intersection::getProcessedVehicles() const
{
    return lane1.getTotalProcessed() + lane2.getTotalProcessed();
}

int Intersection::getProcessedEmergencyVehicles() const
{
    return lane1.getTotalEmergencyProcessed() + lane2.getTotalEmergencyProcessed();
}

bool Intersection::isEmergencyActive() const // checks if either light is in emergency mode; used for terminal output warning message
{
    return light1.isEmergencyMode() || light2.isEmergencyMode();
}