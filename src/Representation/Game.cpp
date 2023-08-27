//
// Created by marcel on 23/11/2022.
//

#include "Game.h"
#include "StateManager.h"
#include "Menu.h"
shared_ptr<StopWatch> StopWatch::stopwatch = nullptr;

Game::Game(int width2, int height2) {
    width = width2;
    height = height2;
}

void Game::runGame(){
    //// setting the window
    RenderWindow renderWindow(VideoMode(width, height), "<Meatboy/>");
    renderWindow.setFramerateLimit(60);
    ///// create window and factory
    StateManager stateManager;
    ConcreteWindow window(width, height, renderWindow, stateManager);

    stateManager.addState(shared_ptr<State>(new Menu(renderWindow, stateManager, width, height)));


    while (window.isOpen()){
        stateManager.processStateChanges();
        stateManager.getTopStack()->handleInput();
        stateManager.getTopStack()->update();
    }
}




