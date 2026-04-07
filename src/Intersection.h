#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Lane.h"
#include"TrafficLight.h"
#include"Vehicle.h"
#include <string>
using namespace std;

class Intersection
{
    private:
        TrafficLight light1;
        TrafficLight light2;
        Lane lane1;
        Lane lane2;

    public:
        Intersection();
        void update(int timer);
        void vehicleToLane1(const Vehicle& v);
        void vehicleToLane2(const Vehicle& v);
        int getQueueLength1() const;
        int getQueueLength2() const;
        string getLight1State() const;
        string getLight2State() const;
        int getProcessedVehicles() const;
        int getProcessedEmergencyVehicles() const;
        bool isEmergencyActive() const;
};

#endif

