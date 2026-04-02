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

public:
    Lane(TrafficLight* light, float length);
    void update(int deltaTime);
    void updateWaitTimes(int deltaTime);
    void addVehicle(const Vehicle& v);
    int getQueueLength() const;
    int getTotalProcessed() const;
    bool isEmpty() const;
};

#endif