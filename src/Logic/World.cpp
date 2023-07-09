//
// Created by marcel on 27/11/2022.
//

#include "World.h"

World::World(AbstractFactory &abstract_factory, Logic_Window &logic_window) : abstract_factory(abstract_factory), logic_window(logic_window) {}


void World::gameLoop() {
    /*
     * if the window is open do the following:
     * 1. clear the screen
     * 2. display all the data the window has
     * 3. check if the screen needs to be closed if so end the loop
     * */
    while(logic_window.isOpen()){
        this->logic_window.clear();
        this->logic_window.display();
        this->logic_window.if_close();


    }

}
