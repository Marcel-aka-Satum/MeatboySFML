//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_ABSTRACTFACTORY_H
#define PROJECTAP_ABSTRACTFACTORY_H

#include "World.h"


/*
 * AbstractFactory class for creating logic entitites from Representation
 * */
class AbstractFactory{
public:
    virtual std::shared_ptr<MeatboyLogic> create_meatboy(World& w, float x, float y)=0;

    virtual std::shared_ptr<WallLogic> create_wall(World& w, float x, float y, float width, float height)=0;

    virtual std::shared_ptr<EndgoalLogic> create_endgoal(World& w, float x, float y, float width, float height)=0;

    virtual std::shared_ptr<SpikeLogic> create_spike(World& w, float x, float y, float width, float height, bool isDynamic, float x2, float y2)=0;
};


#endif //PROJECTAP_ABSTRACTFACTORY_H
