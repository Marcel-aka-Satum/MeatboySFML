//
// Created by marcel on 09/07/2023.
//

#ifndef PROJECTAP_CONCRETEFACTORY_H
#define PROJECTAP_CONCRETEFACTORY_H

#include "../Logic/AbstractFactory.h"
#include "vector"
#include "Entity.h"

using namespace std;
using namespace sf;


/***
 * ConcreteFactory for creating logic entities liked to a representative entity
 */
class ConcreteFactory : public AbstractFactory{
private:
    RenderWindow& window;

public:
    explicit ConcreteFactory(RenderWindow& window2);

    shared_ptr<MeatboyLogic> create_meatboy(World& w, float x, float y) override;

    shared_ptr<WallLogic> create_wall(World& w, float x, float y, float width, float height) override;

    shared_ptr<EndgoalLogic> create_endgoal(World& w, float x, float y, float width, float height)override;

    shared_ptr<SpikeLogic> create_spike(World& w, float x, float y, float width, float height, bool isDynamic, float x2, float y2) override;


};


#endif //PROJECTAP_CONCRETEFACTORY_H
