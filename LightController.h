#ifndef LIGHTCONTROLLER_H
#define LIGHTCONTROLLER_H

#include "TrafficLight.h"
using namespace std;

class LightController {
private:
    TrafficLight light;
    bool emergencyMode;

public:
    LightController(int greenDuration = 5, int yellowDuration = 2, int redDuration = 3);

    void update(bool emergencyDetected);

    void activateEmergencyMode();
    void deactivateEmergencyMode();

    bool canVehiclesMove() const;
    bool isEmergencyMode() const;

    LightState getLightState() const;
    string getLightStateString() const;
};

#endif