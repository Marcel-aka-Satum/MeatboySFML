//
// Created by marcel on 27/08/2023.
//

#include "StateManager.h"

StateManager::StateManager() {
    isAdding= false;
    isRemoving=false;
    isReplacing= false;
}

void StateManager::addState(shared_ptr<State> newState2, bool isReplacing2) {
    isAdding = true;
    isReplacing = isReplacing2;
    newState = std::move(newState2);
}

void StateManager::removeState() {
    isRemoving= true;
}

void StateManager::processStateChanges() {
    //add state
    if(isAdding){
        if(!states.empty()){
            if(isReplacing){
                states.pop();
            }
        }
        states.push(newState);
        states.top()->init();
        isAdding= false;
    }
    //remove state when stack is not empty
    if(isRemoving && !states.empty()){
        states.pop();
        isRemoving = false;
    }
}

shared_ptr<State> StateManager::getTopStack() {
    return states.top();
}

StateManager::~StateManager()=default;


