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
        void tick();
        int getCurrentTime() const;
        int getTimer() const;
        bool isDone() const;
};

#endif