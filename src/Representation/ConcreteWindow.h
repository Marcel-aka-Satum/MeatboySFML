//
// Created by marcel on 06/07/2023.
//

#ifndef PROJECTAP_CONCRETEWINDOW_H
#define PROJECTAP_CONCRETEWINDOW_H

#include "../Logic/AbstractWindow.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


/*
 * Representation window
 * */
class ConcreteWindow : public AbstractWindow {
private:
    RenderWindow& window;
    int width;
    int height;
public:
    ConcreteWindow(int width2, int height2, RenderWindow& window2);
    virtual void clear() override;
    virtual void close() override;
    virtual char checkInput() override;
    virtual void display() override;
    virtual bool isOpen() override;

};


#endif //PROJECTAP_CONCRETEWINDOW_H
