//
// Created by marcel on 06/08/2023.
//

#include "StopWatch.h"

StopWatch::StopWatch() {
    previousTime = chrono::steady_clock::now();
    deltaTime=0;
    timeMultiplier=60;
}

shared_ptr<StopWatch> StopWatch::getStopWatch() {
    if(stopwatch == nullptr)
        stopwatch = shared_ptr<StopWatch>(new StopWatch);
    return stopwatch;
}

void StopWatch::nextFrame() {
    auto currentTime = chrono::steady_clock::now();
    chrono::duration<float> timeDiff = currentTime - previousTime;
    deltaTime = timeDiff.count();
    previousTime = currentTime;
}

float StopWatch::getTimeMultiplier() const {
    return deltaTime * timeMultiplier;
}



