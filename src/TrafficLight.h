#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <string>
using namespace std;

enum class LightState 
{
    RED,
    YELLOW,
    GREEN
}; // possible light states


class TrafficLight {

private:

    LightState state; // current light state
    int timer; // counts time spent in current state

    int greenDuration; // green light duration
    int yellowDuration; // yellow light duration
    int redDuration; // red light duration

    bool emergencyMode; // true if emergency override active


public:

    TrafficLight(int greenDuration, int yellowDuration , int redDuration); // constructor

    void update(bool emergencyDetected); // update light each simulation step
    void activateEmergencyMode(); // force green for emergency vehicle
    void deactivateEmergencyMode(); // return to normal cycle
    bool canVehiclesMove() const; // check if vehicles can move
    bool isEmergencyMode() const; // return emergency mode status
    LightState getState() const; // return current light state
    string getStateAsString() const; // return state as string
    void updateNormalCycle(); // run normal red-yellow-green cycle
    void forceRed();
};

#endif