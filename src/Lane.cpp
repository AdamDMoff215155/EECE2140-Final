#include<iostream>
#include "Lane.h"


Lane::Lane(TrafficLight* LIGHTS, float len): light(LIGHTS),laneLength(len), totalVehiclesProcessed(0), totalEmergencyProcessed(0){} //establsihes lane; references TrafficLight class for light state and sets lane length


void Lane::addVehicle(const Vehicle& v) //adds vehicle to lanes queue
{
    vehicles.push_back(v);
}   

void Lane::update(int timer) //updates lane each tick; moves vehicles if light is green, stops them if red or yellow; also checks if front vehicle has passed the end of the lane and updates processed counts accordingly
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

Vehicle& Lane::getFrontVehicle() // returns a refernce to the front vehicle in the lane; used for checking emergency vehicles in intersection class
{
    return vehicles.front();
}

int Lane::getTotalEmergencyProcessed() const 
{
    return totalEmergencyProcessed;
}
