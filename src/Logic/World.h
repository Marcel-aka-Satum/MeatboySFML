//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include "Logic_Window.h"
#include "EntityLogic.h"

class AbstractFactory;

class World {
public:
    /***
     * Create new game world
     *
     * */
    World(AbstractFactory& abstract_factory, Logic_Window& logic_window);

    /***
     * Game loop
     * */
    void gameLoop();

private:
    AbstractFactory& abstract_factory;
    Logic_Window& logic_window;





};


#endif //PROJECTAP_WORLD_H
