//
// Created by marcel on 06/07/2023.
//

#include "ConcreteWindow.h"

ConcreteWindow::ConcreteWindow(int width2, int height2, RenderWindow& window2, StateManager& stateManager2) : window(window2), stateManager(stateManager2) {
    width = width2;
    height = height2;
    background.loadFromFile("images/sakuraIMG.jpg");
    sprite.setTexture(background);
}

void ConcreteWindow::clear() {
    window.clear(Color::Black);
}

void ConcreteWindow::close() {
    window.close();
}

void ConcreteWindow::display() {
    window.display();
}

bool ConcreteWindow::isOpen() {
    return window.isOpen();
}

void ConcreteWindow::key_board_press(char *keys_pressed) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        keys_pressed[0] = 'A';
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        keys_pressed[1] = 'D';
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        keys_pressed[2] = 'W';
    }
    if(Keyboard::isKeyPressed(Keyboard::Escape)) {
        // this should show the menu when player clicks on Escape button
        stateManager.removeState();
        keys_pressed[3] = 'E';
    }
}

float ConcreteWindow::getWindowHeight() {
    return height;
}

float ConcreteWindow::getWindowWidth() {
    return width;
}

void ConcreteWindow::checkClose() {
    sf::Event event;
    window.pollEvent(event);
    if (event.type == sf::Event::Closed)
        this->window.close();
}

void ConcreteWindow::draw() {
    this->window.draw(sprite);
}







