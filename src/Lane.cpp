#include<iostream>
#include "Lane.h"


Lane::Lane(TrafficLight* LIGHTS, float len): light(LIGHTS),laneLength(len), totalVehiclesProcessed(0), totalEmergencyProcessed(0){}


void Lane::addVehicle(const Vehicle& v) 
{
    vehicles.push_back(v);
}   

void Lane::update(int timer) 
{
    if (vehicles.empty()) 
    {
        return;
    } 

    if (light->getState() == LightState::GREEN) 
    {
        //Apply acceleration and movement to ALL vehicles in the lane
        for (auto& v : vehicles) {
            v.accelerate(timer);
            v.move(timer);
        }
        
        //Check if the front vehicle has passed the end of the lane
        if (vehicles.front().getPosition() >= laneLength) 
        {
            //If the front vehicle is an emergency vehicle, increment the emergency processed count
            if (vehicles.front().isEmergency()) {
                totalEmergencyProcessed++;
            }
            vehicles.pop_front();
            totalVehiclesProcessed++;
        }
    } 
    else 
    {
        //Red or Yellow light: all vehicles must stop
        for (auto& v : vehicles)
        {
            v.stop();
        }
    }
}

void Lane::updateWaitTimes(int timer) 
{
    for (auto& v : vehicles) 
    {
        v.updateWaitTime(timer);
    }
}


int Lane::getQueueLength() const 
{
    return static_cast<int>(vehicles.size());
}

int Lane::getTotalProcessed() const 
{
    return totalVehiclesProcessed;
}

bool Lane::isEmpty() const 
{
    return vehicles.empty();
}

Vehicle& Lane::getFrontVehicle()
{
    return vehicles.front();
}

int Lane::getTotalEmergencyProcessed() const 
{
    return totalEmergencyProcessed;
}
