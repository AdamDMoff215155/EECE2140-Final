#include "Simulator.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Simulator::Simulator(int timer, int endTime): clock(timer, endTime), distribution(1), nextVehicleID(1){}


void Simulator::spawnVehicles()
{
    int numVehicles = distribution(gen);

    for(int i = 0; i < numVehicles; i++)
    {
        bool whatLane = (rand() % 2 == 0); //randomly assign to lane 1 or 2

        // randomly make some vehicles emergency
        bool emergency = (rand() % 10 == 0); // 10% chance

        Vehicle v(nextVehicleID++, "White", emergency, 0.0, 10.0, 10.0);
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

void Simulator::run()
{
    while (!clock.isDone())
    {
        //Spawn vehicles every 3 seconds instead of every tick to avoid overcrowding
        if (clock.getCurrentTime() % 3 == 0) {
            spawnVehicles();
        }
        
        intersection.update(clock.getTimer());
        stats.collect(intersection, clock.getCurrentTime());

        //Terminal animation: clear the screen using ANSI escape codes
        cout << "\033[2J\033[1;1H"; 

        cout << "======================================================" << endl;
        cout << " 🚦 SMART TRAFFIC INTERSECTION SIMULATOR (Time: " << clock.getCurrentTime() << "s)" << endl;
        
        //Highlight emergency vehicle presence with a warning message
        if (intersection.isEmergencyActive()) {
            cout << " 🚨🚨🚨 WARNING: EMERGENCY VEHICLE DETECTED! 🚨🚨🚨" << endl;
        }

        cout << "======================================================" << endl;
        
        cout << "Light 1 State: [" << intersection.getLight1State() << "] | Queue: " << intersection.getQueueLength1() << " cars" << endl;
        cout << "Light 2 State: [" << intersection.getLight2State() << "] | Queue: " << intersection.getQueueLength2() << " cars" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "Total Vehicles Processed: " << intersection.getProcessedVehicles() << endl;
        cout << "======================================================" << endl;

        clock.tick();

        //Pause the thread for 0.5 seconds to create an animation frame
        this_thread::sleep_for(chrono::milliseconds(500)); 
    }

    //Clear the screen one last time and print final statistics
    cout << "\033[2J\033[1;1H"; 
    stats.printSummary();
    cout << "\n✅ Simulation Complete!" << endl;
}

