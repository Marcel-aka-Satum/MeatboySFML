//
// Created by marcel on 06/07/2023.
//

#include "ConcreteWindow.h"

ConcreteWindow::ConcreteWindow(int width2, int height2, RenderWindow& window2) : window(window2) {
    width = width2;
    height = height2;
}

void ConcreteWindow::clear() {
    window.clear(Color::Black);
}

void ConcreteWindow::close() {
    window.close();
}

char ConcreteWindow::checkInput() {
    if(Keyboard::isKeyPressed(Keyboard::Q)) return 'q';

    if(Keyboard::isKeyPressed(Keyboard::D)) return 'd';

    if(Keyboard::isKeyPressed(Keyboard::Space)) return 's';
}

void ConcreteWindow::display() {
    window.display();
}

bool ConcreteWindow::isOpen() {
    window.isOpen();
}




