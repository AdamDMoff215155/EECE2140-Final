#include "SimClock.h"
#include <iostream>

        SimClock::SimClock(int time, int timeEnd): currentTime(0), timer(time), endTime(timeEnd){}
        void SimClock::tick()
        {
            currentTime += timer;
        }
        
        int SimClock:: getCurrentTime() const
        {
            return currentTime;
        }

        int SimClock:: getTimer() const
        {
            return timer;
        }

        bool SimClock:: isDone() const
        {
            return currentTime >= endTime;
        }