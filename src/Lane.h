#ifndef LANE_H
#define LANE_H

#include <deque>
#include "Vehicle.h"
#include "TrafficLight.h"

class Lane {
    std::deque<Vehicle> vehicles;
    TrafficLight* light;
    float laneLength;
    int totalVehiclesProcessed;
    int totalEmergencyProcessed;

public:
    Lane(TrafficLight* light, float length); //establishes lane; references TrafficLight class for light state and sets lane length
    void update(int timer);//updates lane each tick; moves vehicles if light is green, stops them if red or yellow; also checks if front vehicle has passed the end of the lane and updates processed counts accordingly
    void addVehicle(const Vehicle& v);
    int getQueueLength() const;
    int getTotalProcessed() const;
    int getTotalEmergencyProcessed() const;
    bool isEmpty() const;
    Vehicle& getFrontVehicle();// returns a refernce to the front vehicle in the lane; used for checking emergency vehicles in intersection class
};

#endif