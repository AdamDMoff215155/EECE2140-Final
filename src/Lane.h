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
    Lane(TrafficLight* light, float length);
    void update(int timer);
    void addVehicle(const Vehicle& v);
    int getQueueLength() const;
    int getTotalProcessed() const;
    int getTotalEmergencyProcessed() const;
    bool isEmpty() const;
    Vehicle& getFrontVehicle();
};

#endif