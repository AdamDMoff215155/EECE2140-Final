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
    Stats();
    void collect(const Intersection& intersection, int currentTime);
    void printSummary() const;
};

#endif