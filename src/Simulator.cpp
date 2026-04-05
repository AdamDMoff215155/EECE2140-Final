#include "Simulator.h"
#include <iostream>
using namespace std;

Simulator::Simulator(int timer, int endTime): clock(timer, endTime), distribution(1)
{
    nextVehicleID = 1;
}

void Simulator::spawnVehicles()
{
    int numVehicles = distribution(gen);

    for(int i = 0; i < numVehicles; i++)
    {
        bool whatLane = (rand() % 2 == 0); //randomly assign to lane 1 or 2

        // randomly make some vehicles emergency
        bool emergency = (rand() % 10 == 0); // 10% chance

        Vehicle v(nextVehicleID++, "White", emergency, 0.0, 10.0);
        if(whatLane)
        {
            intersection.vehicleToLane1(v);
        }

        else
        {
            intersection.vehicleToLane2(v);
        }
    }
}

void Simulator :: run()
{
    cout << "Starting" << endl;

    while (!clock.isDone())
    {
        spawnVehicles();
        intersection.update(clock.getTimer());
        stats.collect(intersection, clock.getCurrentTime());

        if(clock.getCurrentTime() % 10 ==0)
        {
            cout << "Time: " << clock.getCurrentTime() << " | Lane A Queue: " << intersection.getQueueLength1()
                << " | Lane B Queue: " << intersection.getQueueLength2() << " | Light A: " << intersection.getLight1State() << " | Light B: " << intersection.getLight2State()
                << " | Processed: " << intersection.getProcessedVehicles() << endl;
        }

        clock.tick();
    }

    stats.printSummary();
    cout << "Complete" << endl;
}

