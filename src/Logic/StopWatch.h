//
// Created by marcel on 06/08/2023.
//

#ifndef PROJECTAP_STOPWATCH_H
#define PROJECTAP_STOPWATCH_H


#include "iostream"
#include "memory"
#include "chrono"
#include "shared_mutex"
using namespace std;


///singleton class StopWatch
class StopWatch{
private:
    chrono::time_point<chrono::steady_clock> previousTime;
    static shared_ptr<StopWatch> stopwatch;
    float deltaTime;
    float timeMultiplier;
    StopWatch();
public:
    StopWatch(StopWatch&) = delete;
    void operator=(StopWatch&) = delete;
    /**
      * getter for stopwatch object
      * */
    static shared_ptr<StopWatch> getStopWatch();
    /**
      * get difference between previous frame and initialise new frames
      * */
    void nextFrame();

    /**
      * deltaTime * timeMultiplier so the player moves smoothly even with different monitor hz
      * */
    float getTimeMultiplier() const;
};


#endif //PROJECTAP_STOPWATCH_H
