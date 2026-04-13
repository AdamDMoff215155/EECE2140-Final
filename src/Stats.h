#ifndef STATS_H
#define STATS_H

#include "Intersection.h"
#include <iostream>
using namespace std;

class Stats
{
    private:
    int totalVehiclesProcessed;
    float totalWaitTime;
    int maxQueueLength;
    int tickCount;
    int totalEmergencyProcessed;

    public:
    Stats(); // constructor initializes all stats to 0
    void collect(const Intersection& intersection, int currentTime); // collects statistics each tick; updates total vehicles processed, total wait time, max queue length, and total emergency vehicles processed based on current state of the intersection
    void printSummary() const;
};

#endif