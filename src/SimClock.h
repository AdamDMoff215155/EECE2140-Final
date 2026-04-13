#ifndef SIMCLOCK_H
#define SIMCLOCK_H

class SimClock
{
    private:
        int currentTime;
        int timer;
        int endTime;
    
    public:
        SimClock(int timer, int endTime);
        void tick(); // advances the clock by one tick; updates current time and checks if simulation is done
        int getCurrentTime() const;
        int getTimer() const;
        bool isDone() const; // checks if current time has reached or exceeded end time; returns true if simulation should end
};

#endif