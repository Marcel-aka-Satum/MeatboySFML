//
// Created by marcel on 27/08/2023.
//

#include "Menu.h"

Menu::Menu(RenderWindow &window2, StateManager &stateManager2, float width2, float height2) : window(window2), stateManager(stateManager2) {
    width=width2;
    height=height2;
    selectedItem=0;
}

void Menu::init() {
    if(!font.loadFromFile("././Menu/fonts/ARIAL.ttf") || !background.loadFromFile("././Menu/images/menuBackground.jpg")){
        cout << "ERROR: failed to load file!" << endl;
    }
    sprite.setTexture(background);
    sprite.setTextureRect(IntRect(0,40,width,height));
    menu[0].setFont(font);
    menu[0].setFillColor(Color::Blue);
    menu[0].setString("Play");
    menu[0].setPosition(width / 2 - 40, height / (MAX_NUMBER + 1) * 1);

    menu[1].setFont(font);
    menu[0].setFillColor(Color::Red);
    menu[1].setString("Exit");
    menu[1].setPosition(width / 2 - 40, height / (MAX_NUMBER + 1) * 2);

}

void Menu::handleInput() {
    Event event;
    while(window.pollEvent(event)) {
        if(event.type == Event::Closed) {
            window.close();
        }
        if(event.type == Event::KeyPressed) {
            if(event.key.code == Keyboard::Key::Up)
                moveUp();
            if(event.key.code == Keyboard::Key::Down)
                moveDown();
            if(event.key.code == Keyboard::Key::Return) {
                if(selectedItem == 0) {
                    stateManager.addState(make_shared<MenuLevel>(window, stateManager, width, height), false);
                } else if(selectedItem == 1) {
                    window.close();
                }
            }
        }
    }
}

void Menu::update() {
    draw();
}

void Menu::draw() {
    window.clear();
    window.draw(sprite);
    for(int i = 0; i < MAX_NUMBER; i++) {
        window.draw(menu[i]);
    }
    window.display();
}

void Menu::moveUp() {
    if(selectedItem - 1 >= 0) {
        menu[selectedItem].setFillColor(Color::Black);
        selectedItem--;
        menu[selectedItem].setFillColor(Color::Red);
    }
}

void Menu::moveDown() {
    if(selectedItem + 1 < MAX_NUMBER) {
        menu[selectedItem].setFillColor(Color::Black);
        selectedItem++;
        menu[selectedItem].setFillColor(Color::Red);
    }
}

