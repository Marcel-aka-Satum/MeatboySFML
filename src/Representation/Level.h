//
// Created by marcel on 27/08/2023.
//

#ifndef PROJECTAP_LEVEL_H
#define PROJECTAP_LEVEL_H

#include "State.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "ConcreteWindow.h"


using namespace std;
using namespace sf;

class Level : public State{
private:
    float width,height;
    RenderWindow& window;
    string path, path1, path2;
    StateManager& stateManager;


public:
    Level(RenderWindow& window2, StateManager& stateManager2, float width2, float height2, string p1, string p2, string p3);

    /// initializes menu and the text
    void init() override;
    /// handles input
    void handleInput() override;
    /// updates menu
    void update() override;
    /// draws menu and the text
    void draw() override;



};


#endif //PROJECTAP_LEVEL_H
