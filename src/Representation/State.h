//
// Created by marcel on 27/08/2023.
//

#ifndef PROJECTAP_STATE_H
#define PROJECTAP_STATE_H

class State {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void handleInput() = 0;
};

#endif //PROJECTAP_STATE_H
