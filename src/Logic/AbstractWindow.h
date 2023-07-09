//
// Created by marcel on 09/07/2023.
//

#ifndef PROJECTAP_ABSTRACTWINDOW_H
#define PROJECTAP_ABSTRACTWINDOW_H


class AbstractWindow{
public:
    virtual void clear()=0;
    virtual void close()=0;
    virtual char checkInput()=0;
    virtual void display()=0;
    virtual bool isOpen()=0;
};

#endif //PROJECTAP_ABSTRACTWINDOW_H
