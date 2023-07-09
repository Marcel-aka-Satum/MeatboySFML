//
// Created by marcel on 23/11/2022.
//

#ifndef PROJECTAP_GAME_H
#define PROJECTAP_GAME_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include "../Logic/World.h"
#include "ConcreteWindow.h"
#include "ConcreteFactory.h"


using namespace std;
using namespace sf;


class Game {
private:
    int width;
    int height;
public:
    /* Initialize private vars of the class Game, width and height
     * @param width
     * @param height
     * */
    Game(int width2, int height2);

    /* This function will render the window and keep the program running as long as the game window is open or the game hasn't ended.
     * */
    void runGame();
};


#endif //PROJECTAP_GAME_H
