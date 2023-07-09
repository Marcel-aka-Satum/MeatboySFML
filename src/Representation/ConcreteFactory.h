//
// Created by marcel on 09/07/2023.
//

#ifndef PROJECTAP_CONCRETEFACTORY_H
#define PROJECTAP_CONCRETEFACTORY_H

#include "../Logic/AbstractFactory.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class ConcreteFactory : public AbstractFactory{
private:
    RenderWindow& window;

public:
    explicit ConcreteFactory(RenderWindow& window2);
    ~ConcreteFactory();
    virtual std::shared_ptr<menuLogic> create_menu(World& w) override;
    virtual std::shared_ptr<meatboyLogic> create_meatboy(World& w) override;

};


#endif //PROJECTAP_CONCRETEFACTORY_H
