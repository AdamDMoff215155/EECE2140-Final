#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenDuration, int yellowDuration, int redDuration)
{
    state = LightState::RED;
    timer = 0;
    this->greenDuration = greenDuration;
    this->yellowDuration = yellowDuration;
    this->redDuration = redDuration;
}

void TrafficLight::setState(LightState newState)
{
    state = newState;
    timer = 0;
}

LightState TrafficLight::getState() const
{
    return state;
}

string TrafficLight::getStateString() const
{
    if (state == LightState::RED)
        return "RED";
    else if (state == LightState::YELLOW)
        return "YELLOW";
    else
        return "GREEN";
}

void TrafficLight::tick()
{
    timer++;
}

void TrafficLight::resetTimer()
{
    timer = 0;
}

int TrafficLight::getTimer() const
{
    return timer;
}

int TrafficLight::getGreenDuration() const
{
    return greenDuration;
}

int TrafficLight::getYellowDuration() const
{
    return yellowDuration;
}

int TrafficLight::getRedDuration() const
{
    return redDuration;
}

void TrafficLight::updateNormalCycle()
{
    timer++;

    if (state == LightState::GREEN && timer >= greenDuration)
    {
        state = LightState::YELLOW;
        timer = 0;
    }
    else if (state == LightState::YELLOW && timer >= yellowDuration)
    {
        state = LightState::RED;
        timer = 0;
    }
    else if (state == LightState::RED && timer >= redDuration)
    {
        state = LightState::GREEN;
        timer = 0;
    }
}