//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_ABSTRACTFACTORY_H
#define PROJECTAP_ABSTRACTFACTORY_H

#include "World.h"
#include "memory"

/*
 * AbstractFactory class for creating logic entitites
 * */
class AbstractFactory{
public:
    virtual std::shared_ptr<menuLogic> create_menu(World& w)=0;
    virtual std::shared_ptr<meatboyLogic> create_meatboy(World& w)=0;


};


#endif //PROJECTAP_ABSTRACTFACTORY_H
