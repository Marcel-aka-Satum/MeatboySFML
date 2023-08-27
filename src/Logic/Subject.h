//
// Created by marcel on 02/08/2023.
//

#ifndef PROJECTAP_SUBJECT_H
#define PROJECTAP_SUBJECT_H


#include "Observer.h"
#include "iostream"
#include "list"
using namespace std;

/*
 * Items that need an observer
 * */
class Subject{
private:
    list<Observer*> observerList;
public:
    /**
      * adds an observer to the observerlist
      * */
    void addObserver(Observer* o){
        observerList.push_back(o);
    }
    /**
      * removes an observer from the observerlist
      * */
    void removeObserver(Observer* o){
        observerList.remove(o);
    }
    /**
      * updates the observer list
      * */
    void updateListObserver(){
        for(auto i = observerList.begin(); i != observerList.end(); i++){
            (*i)->update();
        }
    }

    /**
      * destructor
      * */
    ~Subject(){
        for(auto i = observerList.begin(); i != observerList.end(); i++){
            delete (*i);
        }
    }

};


#endif //PROJECTAP_SUBJECT_H
