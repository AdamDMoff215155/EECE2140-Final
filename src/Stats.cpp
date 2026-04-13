#include "Stats.h"
#include <iostream>
using namespace std;

    Stats:: Stats():totalVehiclesProcessed(0), maxQueueLength(0), tickCount(0), totalEmergencyProcessed(0){} // constructor initializes all stats to 0

    void Stats:: collect(const Intersection& intersection, int currentTime) // collects statistics each tick; updates total vehicles processed, total wait time, max queue length, and total emergency vehicles processed based on current state of the intersection
{
    tickCount++;
    totalVehiclesProcessed = intersection.getProcessedVehicles();
    
    totalEmergencyProcessed = intersection.getProcessedEmergencyVehicles(); 

    int currentQueueLength = intersection.getQueueLength1() + intersection.getQueueLength2();
    if(currentQueueLength > maxQueueLength) {
        maxQueueLength = currentQueueLength;
    }
}

    void Stats::printSummary() const
    {
        cout << "Statistics:" << endl;
        cout << "Total Vehicles Processed: " << totalVehiclesProcessed << endl;
        cout << "Emergency Vehicles Processed: " << totalEmergencyProcessed << endl;
        cout << "Max Queue Length: " << maxQueueLength << endl;
        cout << "Total Ticks: " << tickCount << endl;
    }



