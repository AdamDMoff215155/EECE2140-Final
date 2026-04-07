#include "Stats.h"
#include <iostream>
using namespace std;

    Stats:: Stats():totalVehiclesProcessed(0), maxQueueLength(0), tickCount(0), totalEmergencyProcessed(0){}

    void Stats:: collect(const Intersection& intersection, int currentTime)
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



