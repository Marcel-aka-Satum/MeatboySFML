//
// Created by marcel on 09/07/2023.
//

#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory(RenderWindow &window2) : window(window2){

}

std::shared_ptr<menuLogic> ConcreteFactory::create_menu(World &w) {
    return std::shared_ptr<menuLogic>();
}

std::shared_ptr<meatboyLogic> ConcreteFactory::create_meatboy(World &w) {
    return std::shared_ptr<meatboyLogic>();
}

ConcreteFactory::~ConcreteFactory()=default;



