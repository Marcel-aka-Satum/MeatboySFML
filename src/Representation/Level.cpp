//
// Created by marcel on 27/08/2023.
//

#include "Level.h"
#include "ConcreteFactory.h"


Level::Level(RenderWindow &window2, StateManager &stateManager2, float width2, float height2, string p1, string p2,string p3) : window(window2), stateManager(stateManager2) {
    width = width2;
    height = height2;
    path = std::move(p1);
    path1 = std::move(p2);
    path2 = std::move(p3);
}

void Level::init() {

}

void Level::handleInput() {

}

void Level::update() {
    ConcreteFactory factory(window);
    ConcreteWindow concreteWindow(width,height, window, stateManager);
    World world(factory, concreteWindow);
    const char* c = path.data();
    world.init(c);
    world.gameLoop();
    // go to the next level
    if(world.getNextLVL() && path1 != "None"){
        stateManager.addState(make_shared<Level>(window, stateManager, width, height, path1, path2, "None"));
    }
}

void Level::draw() {

}

