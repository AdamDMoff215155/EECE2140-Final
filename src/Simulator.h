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

    default_random_engine gen; //random number generator for vehicle spawning
    poisson_distribution<int> distribution;//poisson distribution to determine number of vehicles spawned each tick; average of 1 vehicle per tick

    public:
    Simulator(int timer, int endTime); // constructor initializes clock with timer and end time; sets up poisson distribution for vehicle spawning; initializes next vehicle ID to 1
    void run(); // main simulation loop; runs until clock is done; spawns vehicles, updates intersection and stats, and prints terminal output each tick
    void spawnVehicles(); // spawns a random number of vehicles; randomly assigns them to lane 1 or 2; also randomly makes some vehicles emergency vehicles

};

#endif