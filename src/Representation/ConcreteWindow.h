//
// Created by marcel on 06/07/2023.
//

#ifndef PROJECTAP_CONCRETEWINDOW_H
#define PROJECTAP_CONCRETEWINDOW_H

#include "../Logic/AbstractWindow.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"
using namespace std;
using namespace sf;


/*
 * Representation window
 * */
class ConcreteWindow : public AbstractWindow {
private:
    RenderWindow& window;
    float width;
    float height;
    Texture background;
    Sprite sprite;
    StateManager& stateManager;


public:
    ConcreteWindow(int width2, int height2, RenderWindow& window2, StateManager& stateManager2);
    ///clears the screen
    void clear() override;
    ///checks for keyboardpresses
    void key_board_press(char* keys_pressed)override;
    ///checks if the window is open
    bool isOpen()override;
    ///getter for windowHeight
    float getWindowHeight()override;
    ///getter for windowWidth
    float getWindowWidth()override;
    ///display things on screen
    void display()override;
    ///close the window
    void close()override;
    ///check if closed
    void checkClose()override;
    ///draw the sprite on the window
    void draw()override;

};


#endif //PROJECTAP_CONCRETEWINDOW_H
