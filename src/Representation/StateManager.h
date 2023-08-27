//
// Created by marcel on 27/08/2023.
//

#ifndef PROJECTAP_STATEMANAGER_H
#define PROJECTAP_STATEMANAGER_H

#include "stack"
#include "State.h"
#include "memory"

using namespace std;
class StateManager {
private:
    stack<shared_ptr<State>> states;
    shared_ptr<State> newState;
    bool isRemoving;
    bool isAdding;
    bool isReplacing;
public:
    StateManager();
    ~StateManager();
    /// adds a state on the stack
    void addState(shared_ptr<State> newState2, bool isReplacing = true);
    /// removes a state from the stack
    void removeState();
    /// processing states
    void processStateChanges();
    /// return top of the stack
    shared_ptr<State> getTopStack();
};


#endif //PROJECTAP_STATEMANAGER_H
