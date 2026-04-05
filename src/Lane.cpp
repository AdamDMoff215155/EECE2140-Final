#include<iostream>
#include "Lane.h"


Lane::Lane(TrafficLight* LIGHTS, float len): light(LIGHTS),laneLength(len), totalVehiclesProcessed(0){}


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

    Vehicle& front = vehicles.front();

    if (light->getState() == LightState::GREEN) 
    {
            front.accelerate(timer); 
            front.move(timer); 
            cout <<"Front vehicle position: " << front.getPosition() << endl;
        if (front.getPosition() >= laneLength) 
        {
            vehicles.pop_front();
            totalVehiclesProcessed++;
        }
    } 

    else 
    {
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
