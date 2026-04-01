#include<iostream>
#include "Lane.h"


Lane::Lane(TrafficLight* light, float length) 
{
    this->light = light;
    this->laneLength = length;
    this->totalVehiclesProcessed = 0;
}


void Lane::addVehicle(const Vehicle& v) 
{
    vehicles.push(v);
}   

void Lane::update(int deltaTime) 
{
    if (vehicles.empty()) 
    {
        return;
    } 

    Vehicle& front = vehicles.front();

    if (light->getState() == TrafficLight::State::GREEN) 
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
