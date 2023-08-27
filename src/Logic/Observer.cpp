//
// Created by marcel on 27/11/2022.
//

#include "Observer.h"
#include "EntityLogic.h"

EntityObserver::EntityObserver(EntityLogic& entityLogic): logicEntity(entityLogic) {
    this->logicEntity.addObserver(this);
}