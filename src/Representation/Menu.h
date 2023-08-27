//
// Created by marcel on 27/08/2023.
//

#ifndef PROJECTAP_MENU_H
#define PROJECTAP_MENU_H

#include "State.h"
#include "StateManager.h"
#include "iostream"
#include "MenuLevel.h"
#include <SFML/Graphics.hpp>
#define MAX_NUMBER 2


using namespace std;
using namespace sf;
class Menu : public State{
private:
    float width,height;
    int selectedItem; // index of selected item in menu (0 will be first from the top so in our case "Play")
    StateManager& stateManager;
    sf::Font font;
    Text menu[MAX_NUMBER];
    Texture background;
    Sprite sprite;
    RenderWindow& window;

public:
    explicit Menu(RenderWindow& window2, StateManager& stateManager2, float width2, float height2);
    /// initializes menu and the text
    void init() override;
    /// handles input
    void handleInput() override;
    /// updates menu
    void update() override;
    /// draws menu and the text
    void draw() override;
    /// move selectedItem up in Menu
    void moveUp();
    /// move selectedItem down in Menu
    void moveDown();

};


#endif //PROJECTAP_MENU_H
