#include "Intersection.h"
#include <iostream>
#include<string>

Intersection::Intersection(): 
    light1(10, 2, 12),        //Change red light duration to 12 (10+2) to sync with cross-traffic
    light2(10, 2, 12),        //Change red light duration to 12 (10+2)
    lane1(&light1, 100.0f),  //Increase lane length to 100.0f for better visualization
    lane2(&light2, 100.0f)   //Increase lane length to 100.0f
{
    light2.forceRed();
}

void Intersection::update(int timer)
{
    bool emergency1 = !lane1.isEmpty() && lane1.getFrontVehicle().isEmergency();
    bool emergency2 = !lane2.isEmpty() && lane2.getFrontVehicle().isEmergency();

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

string Intersection::getLight1State() const
{
    return light1.getStateAsString();
}

string Intersection::getLight2State() const
{
    return light2.getStateAsString();
}

int Intersection::getProcessedVehicles() const
{
    return lane1.getTotalProcessed() + lane2.getTotalProcessed();
}