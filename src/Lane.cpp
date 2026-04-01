#include<iostream>
#include "Lane.h"


Lane::Lane(TrafficLight* LIGHTS, float len): TrafficLight(LIGHTS),laneLength(len), totalVehiclesProcessed(0){}


void Lane::addVehicle(const Vehicle& v) 
{
    vehicles.push(v);
}   

void Lane::update(int deltaTime) 
{
    if (vehicles.empty()) 
    {
        bool emergency = false;
        light ->update(emergency);
        return;
    } 

    Vehicle& front = vehicles.front();
    bool emergency = front.isEmergency();
    light -> update(emergency);

    if (light->getState() == LightState::GREEN) 
    {
        front.accelerate(deltaTime); 
        front.move(deltaTime); 

        if (front.getPosition() >= laneLength) 
        {
            vehicles.pop();
            totalVehiclesProcessed++;
        }
    } 

    else 
    {
        front.stop();
    }
}

void Lane::updateWaitTimes(int deltaTime) 
{
    for (auto& v : vehicles) 
    {
        v.updateWaitTime(deltaTime);
    }
}


int Lane::getQueueLength() const 
{
    return vehicles.size();
}

int Lane::getTotalProcessed() const 
{
    return totalVehiclesProcessed;
}

bool Lane::isEmpty() const 
{
    return vehicles.empty();
}
