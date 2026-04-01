#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenDuration,
                           int yellowDuration,
                           int redDuration)
{
    state = LightState::GREEN; // start with green light
    timer = 0; // initialize timer

    this->greenDuration = greenDuration; // set green duration
    this->yellowDuration = yellowDuration; // set yellow duration
    this->redDuration = redDuration; // set red duration

    emergencyMode = false; // default normal mode
}


void TrafficLight::update(bool emergencyDetected)
{
    if (emergencyDetected)
    {
        activateEmergencyMode(); // switch to emergency mode
    }
    else
    {
        if (emergencyMode)
        {
            deactivateEmergencyMode(); // return to normal mode
        }

        updateNormalCycle(); // continue normal light cycle
    }
}


void TrafficLight::activateEmergencyMode()
{
    emergencyMode = true; // enable emergency mode
    state = LightState::GREEN; // force green light
    timer = 0; // reset timer
}


void TrafficLight::deactivateEmergencyMode()
{
    emergencyMode = false; // disable emergency mode
    state = LightState::GREEN; // restart cycle from green
    timer = 0; // reset timer
}


bool TrafficLight::canVehiclesMove() const
{
    return state == LightState::GREEN; // vehicles move only on green
}


bool TrafficLight::isEmergencyMode() const
{
    return emergencyMode; // return emergency mode status
}


LightState TrafficLight::getState() const
{
    return state; // return current state
}


string TrafficLight::getStateString() const
{
    if (state == LightState::RED)
        return "RED"; // return red

    else if (state == LightState::YELLOW)
        return "YELLOW"; // return yellow

    else
        return "GREEN"; // return green
}


void TrafficLight::updateNormalCycle()
{
    timer++; // increase timer each step

    if (state == LightState::GREEN && timer >= greenDuration)
    {
        state = LightState::YELLOW; // switch to yellow
        timer = 0;
    }

    else if (state == LightState::YELLOW && timer >= yellowDuration)
    {
        state = LightState::RED; // switch to red
        timer = 0;
    }

    else if (state == LightState::RED && timer >= redDuration)
    {
        state = LightState::GREEN; // switch to green
        timer = 0;
    }
}