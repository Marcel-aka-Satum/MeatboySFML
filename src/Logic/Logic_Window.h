//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_LOGIC_WINDOW_H
#define PROJECTAP_LOGIC_WINDOW_H

/*
 * Class for controlling and receiving info from the window
 * */



class Logic_Window{
public:
    virtual void clear()=0;
    virtual void key_board_press(char* keys_pressed)=0;
    virtual bool isOpen()=0;
    virtual int getWindowHeight()=0;
    virtual int getWindowWidth()=0;
    virtual void display()=0;
    virtual void if_close()=0;

};



#endif //PROJECTAP_LOGIC_WINDOW_H
