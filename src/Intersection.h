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
        Intersection(); //establsihes light and lane objects
        void update(int timer);
        void vehicleToLane1(const Vehicle& v);
        void vehicleToLane2(const Vehicle& v);
        int getQueueLength1() const;
        int getQueueLength2() const;
        string getLight1State() const; // return light state as string for terminal output
        string getLight2State() const; // return light state as string for terminal output
        int getProcessedVehicles() const;
        int getProcessedEmergencyVehicles() const;
        bool isEmergencyActive() const; // checks if either light is in emergency mode; used for terminal output warning message
};

#endif

