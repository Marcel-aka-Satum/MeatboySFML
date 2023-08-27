//
// Created by marcel on 27/08/2023.
//

#ifndef PROJECTAP_MENULEVEL_H
#define PROJECTAP_MENULEVEL_H

#include "iostream"
#include "State.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#include "fstream"
#define MAX_NUMBER_LVLS 8


using namespace std;
using namespace sf;

class MenuLevel : public State{
private:
    float width,height;
    int selectedItem; // index of selected item in menu (0 will be first from the bottom)
    RenderWindow& window;
    Texture background;
    Sprite sprite;
    StateManager& stateManager;
    Font font;
    Text menu[MAX_NUMBER_LVLS];
    int amountFiles; // stores how many file lvls there are
    bool isPlaying;

public:
    explicit MenuLevel(RenderWindow& window2, StateManager& stateManager2, float width2, float height2);

    /// initializes menu and the text
    void init() override;
    /// handle input
    void handleInput() override;
    /// update menu
    void update() override;
    /// draws menu and the text
    void draw() override;
    /// move selectedItem up in Menu
    void moveUp();
    /// move selectedItem down in Menu
    void moveDown();
    /// calculate how many levels are there in level directory
    int howManyLevels();

};


#endif //PROJECTAP_MENULEVEL_H
