//
// Created by marcel on 04/12/2022.
//

#ifndef PROJECTAP_ENTITY_H
#define PROJECTAP_ENTITY_H


#include "../Logic/EntityLogic.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

/*
 * Class for drawing entities to the representation window
 * */
class Entity : public EntityObserver{
protected:
    RenderWindow& window;
public:
    Entity(EntityLogic &entityLogic1, RenderWindow &window1);
    virtual void draw()=0;
};

class TextureEntity : public Entity{
protected:
    RectangleShape entityGraphic;
    sf::Texture texture;
public:
    TextureEntity(EntityLogic &logicEntity1, RenderWindow &window1, const char *texturePath);
    /***
     * Updates the location of the representative entity to the logic entity and calls the draw function
     */
    void update() override;

    /***
     * draw the texture to the screen
     */
    void draw() override;
};

class MeatBoy : public TextureEntity{
public:
    MeatBoy(MeatboyLogic& logicEntity, RenderWindow& window);
    void update() override;
    void draw() override;
};

class Wall : public TextureEntity{
public:
    Wall(WallLogic& wallLogic, RenderWindow& window);
    void update() override;
    void draw() override;
};

class EndGoal : public TextureEntity{
public:
    EndGoal(EndgoalLogic& endgoalLogic, RenderWindow& window);
    void update() override;
    void draw() override;
};

class Spike : public TextureEntity{
public:
    Spike(SpikeLogic& spikeLogic, RenderWindow& window);
    void update() override;
    void draw() override;
};



#endif //PROJECTAP_ENTITY_H
