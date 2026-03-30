#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <string>
using namespace std;

enum class LightState {
    RED,
    YELLOW,
    GREEN
};

class TrafficLight {
private:
    LightState state;
    int timer;
    int greenDuration;
    int yellowDuration;
    int redDuration;

public:
    TrafficLight(int greenDuration = 5, int yellowDuration = 2, int redDuration = 3);

    void setState(LightState newState);
    LightState getState() const;
    string getStateString() const;

    void tick();
    void resetTimer();
    int getTimer() const;

    int getGreenDuration() const;
    int getYellowDuration() const;
    int getRedDuration() const;

    void updateNormalCycle();
};

#endif