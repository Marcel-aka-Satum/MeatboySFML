//
// Created by marcel on 27/08/2023.
//

#include "MenuLevel.h"
#include "Level.h"

MenuLevel::MenuLevel(RenderWindow &window2, StateManager &stateManager2, float width2, float height2) : window(window2), stateManager(stateManager2) {
    width = width2;
    height = height2;
    selectedItem = 1;
    amountFiles = howManyLevels();
    isPlaying = false;
}

void MenuLevel::init() {
    if(!font.loadFromFile("././Menu/fonts/ARIAL.ttf") || !background.loadFromFile("././Menu/images/menuBackground.jpg")){
        cout << "ERROR: failed to load file!" << endl;
    }
    sprite.setTexture(background);
    sprite.setTextureRect(IntRect(0,40,width,height));

    for(int i = 1; i<amountFiles+2; i++){
        string nameLevel;
        menu[i].setFont(font);
        if(i==1){
            menu[i].setFillColor(Color::Red);
        } else{
            menu[i].setFillColor(Color::Black);
        }

        if(i != amountFiles+1){
            nameLevel += "Level " + to_string(i);
        } else if(i==amountFiles+1){
            nameLevel="Return";
        }
        menu[i].setString(nameLevel);
        menu[i].setPosition(width / 2 - 60, height / (MAX_NUMBER_LVLS)*i + 200);
    }
}

void MenuLevel::handleInput() {
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
                for(int i = 1; i <= amountFiles; i++){
                    if(selectedItem == i){
                        string path = "././Menu/levels/level";
                        string path1 = "././Menu/levels/level";
                        string path2 = "././Menu/levels/level";
                        path += to_string(i) + ".xml";
                        path1 += to_string(i+1) + ".xml";
                        path2 += to_string(i+2) + ".xml";
                        if(i + 1 > amountFiles){
                            path1 = "None";
                        }
                        if(i +2 > amountFiles){
                            path2 = "None";
                        }
                        stateManager.addState(make_shared<Level>(window, stateManager, width, height, path, path1, path2));
                    }
                }
                if(selectedItem == amountFiles + 1 && !isPlaying){
                    stateManager.removeState();
                }
            }
        }
    }
}


void MenuLevel::draw() {
    window.clear();
    window.draw(sprite);
    if(!isPlaying){
        for(int i = 0; i <MAX_NUMBER_LVLS; i++){
            window.draw(menu[i]);
        }
    }
    window.display();
}

void MenuLevel::update() {
    draw();
}

void MenuLevel::moveUp() {
    if(selectedItem -1 >= 1){
        menu[selectedItem].setFillColor(Color::Black);
        selectedItem--;
        menu[selectedItem].setFillColor(Color::Red);
    }
}

void MenuLevel::moveDown() {
    if(selectedItem +1 <= amountFiles + 1){
        menu[selectedItem].setFillColor(Color::Black);
        selectedItem++;
        menu[selectedItem].setFillColor(Color::Red);
    }
}

int MenuLevel::howManyLevels() {
    int amount = 0;
    for(int i = 0; i < MAX_NUMBER_LVLS; i++){
        string fileName = "././Menu/levels/level" + to_string(i) + ".xml";
        ifstream f(fileName);
        if(f.good()){
            amount++;
        }
    }
    return amount;
}



