//
// Created by marcel on 23/11/2022.
//

#include "Game.h"


Game::Game(int width2, int height2) {
    width = width2;
    height = height2;
}

void Game::runGame(){
    //// setting the window
    RenderWindow renderWindow(VideoMode(width, height), "<Meatboy/>");
    renderWindow.setFramerateLimit(60);
    ConcreteWindow window(width, height, renderWindow);

    /// Setting the background
    Texture texture;
    if (!texture.loadFromFile("images/sakuraIMG.jpg")){
        cout << "cannot load the background" << endl;
        system("pause");
    }
    Sprite background;
    background.setTexture(texture);

    ConcreteFactory factory(renderWindow);

    while (window.isOpen()){
        World world(window, factory);
        world.runGameLoop();
    }
}




