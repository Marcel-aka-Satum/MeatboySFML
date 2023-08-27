//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_OBSERVER_H
#define PROJECTAP_OBSERVER_H

#include "iostream"
using namespace std;

class EntityLogic;

class Observer {
public:
    virtual void update() = 0;
};

class EntityObserver: Observer{
protected:
    EntityLogic& logicEntity;
public:
    EntityObserver(EntityLogic& entityLogic);
};


#endif //PROJECTAP_OBSERVER_H
