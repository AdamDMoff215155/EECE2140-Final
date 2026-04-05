#ifndef SIMULATOR_H
#define SIMULATOR_H

#include<iostream>
#include <random>
#include "SimClock.h"
#include "Intersection.h"
#include "Stats.h"
#include "Vehicle.h"
using namespace std;

class Simulator 
{
    private:
    SimClock clock;
    Intersection intersection;
    Stats stats;
    int nextVehicleID;

    default_random_engine gen;
    poisson_distribution<int> distribution;

    public:
    Simulator(int timer, int endTime);
    void run();
    void spawnVehicles();

};

#endif