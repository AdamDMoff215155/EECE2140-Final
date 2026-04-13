#include "SimClock.h"
#include <iostream>

        SimClock::SimClock(int time, int timeEnd): currentTime(0), timer(time), endTime(timeEnd){} //establishes clock object; initializes current time to 0 and sets timer and end time based on constructor parameters
        void SimClock::tick() // advances the clock by one tick; updates current time and checks if simulation is done
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

        bool SimClock:: isDone() const // checks if current time has reached or exceeded end time; returns true if simulation should end
        {
            return currentTime >= endTime;
        }