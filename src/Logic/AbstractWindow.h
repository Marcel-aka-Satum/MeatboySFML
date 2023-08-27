//
// Created by marcel on 09/07/2023.
//

#ifndef PROJECTAP_ABSTRACTWINDOW_H
#define PROJECTAP_ABSTRACTWINDOW_H

/*
 * Class for controlling and receiving info from the window in Representation
 * */
class AbstractWindow{
public:
    virtual void clear()=0;
    virtual void key_board_press(char* keys_pressed)=0;
    virtual bool isOpen()=0;
    virtual float getWindowHeight()=0;
    virtual float getWindowWidth()=0;
    virtual void display()=0;
    virtual void close()=0;
    virtual void checkClose()=0;
    virtual void draw()=0;

};

#endif //PROJECTAP_ABSTRACTWINDOW_H
