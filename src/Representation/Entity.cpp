//
// Created by marcel on 04/12/2022.
//

#include "Entity.h"
#include "../Logic/World.h"

Entity::Entity(EntityLogic &entityLogic1, RenderWindow &window1) : EntityObserver(entityLogic1), window(window1) {

}

TextureEntity::TextureEntity(EntityLogic &logicEntity1, RenderWindow &window1, const char *texturePath) : Entity(logicEntity1, window1) {
    if(!texture.loadFromFile(texturePath)){
        throw "Texture not found";
    }
    texture.loadFromFile(texturePath);
    entityGraphic.setTexture(&texture);
}

void TextureEntity::update() {

}

void TextureEntity::draw() {

}

MeatBoy::MeatBoy(MeatboyLogic& logicEntity, RenderWindow& window) : TextureEntity(logicEntity, window, "./images/meatboy.png") {
    cout << "Creating meatboy" << endl;
    entityGraphic.setSize(Vector2f(logicEntity.getXSize(), logicEntity.getYSize()));
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
}

void MeatBoy::update() {
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
    this->draw();
}

void MeatBoy::draw() {
    this->window.draw(this->entityGraphic);
}


Wall::Wall(WallLogic &wallLogic, RenderWindow &window) : TextureEntity(wallLogic, window, "./images/wall.png"){
    cout << "creating a wall" << endl;
    entityGraphic.setSize(Vector2f(logicEntity.getXSize(), logicEntity.getYSize()));
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
}

void Wall::update() {
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
    this->draw();
}

void Wall::draw() {
    this->window.draw(this->entityGraphic);
}

EndGoal::EndGoal(EndgoalLogic &endgoalLogic, RenderWindow &window) : TextureEntity(endgoalLogic, window, "./images/endgoal.jpg") {
    cout << "creating Endgoal" << endl;
    entityGraphic.setSize(Vector2f(logicEntity.getXSize(), logicEntity.getYSize()));
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);

}

void EndGoal::update() {
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
    this->draw();
}

void EndGoal::draw() {
    this->window.draw(this->entityGraphic);
}

Spike::Spike(SpikeLogic &spikeLogic, RenderWindow &window) : TextureEntity(spikeLogic, window, "./images/spikes.jpg"){
    cout << "creating spike" << endl;
    entityGraphic.setSize(Vector2f(logicEntity.getXSize(), logicEntity.getYSize()));
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
}

void Spike::update() {
    pair<float, float> newPositions = logicEntity.getWorld().getCamera().convertLogicToPixel(logicEntity.getXLocation(), logicEntity.getYLocation(), logicEntity);
    this->entityGraphic.setPosition(newPositions.first,newPositions.second);
    this->draw();
}

void Spike::draw() {
    this->window.draw(this->entityGraphic);
}
