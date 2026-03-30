#include "LightController.h"

LightController::LightController(int greenDuration, int yellowDuration, int redDuration)
{
    light = TrafficLight(greenDuration, yellowDuration, redDuration);
    emergencyMode = false;

    light.setState(LightState::GREEN);
}

void LightController::update(bool emergencyDetected)
{
    if (emergencyDetected)
    {
        activateEmergencyMode();
    }
    else
    {
        if (emergencyMode)
        {
            deactivateEmergencyMode();
        }

        light.updateNormalCycle();
    }
}

void LightController::activateEmergencyMode()
{
    emergencyMode = true;
    light.setState(LightState::GREEN);
}

void LightController::deactivateEmergencyMode()
{
    emergencyMode = false;
    light.setState(LightState::GREEN);
}

bool LightController::canVehiclesMove() const
{
    return light.getState() == LightState::GREEN;
}

bool LightController::isEmergencyMode() const
{
    return emergencyMode;
}

LightState LightController::getLightState() const
{
    return light.getState();
}

string LightController::getLightStateString() const
{
    return light.getStateString();
}