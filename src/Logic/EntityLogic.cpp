//
// Created by marcel on 28/11/2022.
//

#include "EntityLogic.h"
#include "World.h"

float EntityLogic::getXSize() const{
    return sizeXY.first;
}

float EntityLogic::getYSize() const{
    return sizeXY.second;
}

float EntityLogic::getXLocation() const{
    return locationXY.first;
}

float EntityLogic::getYLocation() const{
    return locationXY.second;
}

World& EntityLogic::getWorld() {
    return this->world;
}

EntityLogic::EntityLogic(World &world) : world(world) {}

bool EntityLogic::checkCollision(EntityLogic &e1, EntityLogic &e2) {
    // values for e1
    float e1MinX = min(e1.getXLocation(), e1.getXLocation() + e1.getXSize());
    float e1MaxX = max(e1.getXLocation(), e1.getXLocation() + e1.getXSize());
    float e1MinY = min(e1.getYLocation(), e1.getYLocation() + e1.getYSize());
    float e1MaxY = max(e1.getYLocation(), e1.getYLocation() + e1.getYSize());

    //values for e2
    float e2MinX = min(e2.getXLocation(), e2.getXLocation() + e2.getXSize());
    float e2MaxX = max(e2.getXLocation(), e2.getXLocation() + e2.getXSize());
    float e2MinY = min(e2.getYLocation(), e2.getYLocation() + e2.getYSize());
    float e2MaxY = max(e2.getYLocation(), e2.getYLocation() + e2.getYSize());

    float interLeft = max(e1MinX,e2MinX);
    float interRight = min(e1MaxX, e2MaxX);
    float interTop = max(e1MinY, e2MinY);
    float interBottom = min(e1MaxY, e2MaxY);


    if((interLeft <= interRight) && (interTop <= interBottom)){
        //Entity1(in our case player) has collision from bottom Entity2(in our case wall) has collision from the top
        if((e1MinY < e2MaxY) && (e1MaxY > e2MaxY) && (e1MaxX != e2MinX) && (e1MinX != e2MaxX)){
            e1.setCollisionBottom(true);
            e1.setCollisionTop(false);

            e2.setCollisionTop(true);
            e2.setCollisionRight(false);
            e2.setCollisionLeft(false);
            e2.setCollisionBottom(false);
        }
        //Entity1(in our case player) has collision from top Entity2(in our case wall) has collision from the bottom
        else if(e1MinY < e2MinY && e1MaxY > e2MinY){
            e1.setCollisionTop(true);
            e1.setCollisionLeft(false);
            e1.setCollisionRight(false);

            e2.setCollisionBottom(true);
            e2.setCollisionTop(false);
            e2.setCollisionRight(false);
            e2.setCollisionLeft(false);
        }
        //Entity1(in our case player) has collision from left Entity2(in our case wall) has collision from the right
        else if(e1MinX > e2MinX && e1MaxX > e2MaxX && e1MinY != e2MaxY){
            e1.setCollisionLeft(true);
            e1.setCollisionTop(false);
            e1.setCollisionRight(false);

            e2.setCollisionRight(true);
            e2.setCollisionLeft(false);
            e2.setCollisionBottom(false);
            e2.setCollisionTop(false);
        }
        //Entity1(in our case player) has collision from right Entity2(in our case wall) has collision from the left
        else if(e1MinX < e2MaxX && e1MinX < e2MinX && e1MinY != e2MaxY){
            e1.setCollisionRight(true);
            e1.setCollisionLeft(false);
            e1.setCollisionTop(false);

            e2.setCollisionRight(false);
            e2.setCollisionLeft(true);
            e2.setCollisionBottom(false);
            e2.setCollisionTop(false);
        }
        return true;
    }
    return false;
}

void EntityLogic::setCollisionLeft(bool collisionLeft2) {
    EntityLogic::collisionLeft = collisionLeft2;
}

void EntityLogic::setCollisionRight(bool collisionRight2) {
    EntityLogic::collisionRight = collisionRight2;
}

void EntityLogic::setCollisionTop(bool collisionTop2) {
    EntityLogic::collisionTop = collisionTop2;
}

void EntityLogic::setCollisionBottom(bool collisionBottom2) {
    EntityLogic::collisionBottom = collisionBottom2;
}

bool EntityLogic::isCollisionLeft() const {
    return collisionLeft;
}

bool EntityLogic::isCollisionRight() const {
    return collisionRight;
}

bool EntityLogic::isCollisionTop() const {
    return collisionTop;
}

bool EntityLogic::isCollisionBottom() const {
    return collisionBottom;
}

void EntityLogic::setGroundHeight(float v) {
    groundHeight = v;
}

MeatboyLogic::MeatboyLogic(World &w, float x, float y) : EntityLogic(w){
    this->sizeXY.first = 20;
    this->sizeXY.second = 20;
    this->locationXY.first = x;
    this->locationXY.second = y;
    this->velocityX = 0;
    this->velocityY = 0;
    isJumping = false;
    jumpForce = 6;
    gravity = 0.2;
    acceleration = 0.3;
    maxVelocity = 5.5;
    isMovingRight = false;
    isMovingLeft = false;
    groundHeight=0;
    jumpChecker= true;
    onGround=true;
}

void MeatboyLogic::update() {
    float nextXPos = locationXY.first;
    float nextYpos = locationXY.second;

    nextYpos += velocityY * world.getStopwatch()->getTimeMultiplier();
    nextXPos += velocityX * world.getStopwatch()->getTimeMultiplier();


    //update previous position to new position
    locationXY.first = nextXPos;
    locationXY.second = nextYpos;
    updateListObserver();
}

void MeatboyLogic::moveRight() {
    isMovingLeft= false;
    isMovingRight=true;
    this->velocityX += 1.f * world.getStopwatch()->getTimeMultiplier();
    if(velocityX > maxVelocity){
        velocityX = maxVelocity;
    }
}

void MeatboyLogic::moveLeft() {
    isMovingRight = false;
    isMovingLeft = true;
    this->velocityX -= 1.f * world.getStopwatch()->getTimeMultiplier();
    if(velocityX < -maxVelocity){
        velocityX = -maxVelocity;
    }
}

void MeatboyLogic::SetMovingLeft(bool a) {
    isMovingLeft = a;
}

void MeatboyLogic::SetMovingRight(bool a) {
    isMovingRight = a;
}

void MeatboyLogic::setIsJumping(bool v) {
    isJumping = v;
}

void MeatboyLogic::slowDown() {
    if(isMovingLeft){
        if(velocityX>=0){
            velocityX=0;
        }else{
            velocityX += 0.2f * world.getStopwatch()->getTimeMultiplier();
        }
    } else if(isMovingRight){
        if(velocityX<=0){
            velocityX=0;
        }else{
            velocityX -= 0.2f * world.getStopwatch()->getTimeMultiplier();
        }
    }
}


void MeatboyLogic::jump() {
    jumpChecker = false;
    velocityY = jumpForce;
}

void MeatboyLogic::downJump() {
    velocityY -= gravity;
}

void MeatboyLogic::checkCollisionWalls(vector<shared_ptr<WallLogic>> &walls) {

    bool bottom,left,right,top = false;

    for(auto& i : walls){
        if(checkCollision(*this, *i)){
            if(collisionRight){
                if(i->isCollisionLeft()){
                    locationXY.first = i->getXLocation() - sizeXY.first;
                    right= true;
                    jumpChecker=true;
                }
            }
            if(collisionLeft){
                if(i->isCollisionRight()){
                    locationXY.first = i->getXLocation() + i->getXSize();
                    left=true;
                    jumpChecker=true;
                }
            }
            if(collisionBottom){
                if(i->isCollisionTop()){
                    if(!i->isCollisionLeft() && !i->isCollisionRight()){
                        locationXY.second = i->getYLocation() + i->getYSize();
                        groundHeight = i->getYLocation() + i->getXSize();
                        velocityY = 0;
                        jumpChecker = true;
                        bottom= true;
                        onGround = true;
                    }
                }
            } else{
                onGround = false;
            }
            if(collisionTop){
                if(i->isCollisionBottom()){
                    velocityY = -gravity;
                    locationXY.second = i->getYLocation() - sizeXY.second;
                    top = true;
                }
            }
        } else{
            i->setCollisionLeft(false);
            i->setCollisionRight(false);
            i->setCollisionBottom(false);
            i->setCollisionTop(false);
        }
    }
    if(!left) {
        collisionLeft = false;
    }
    if(!right) {
        collisionRight = false;
    }
    if(!top) {
        collisionTop = false;
    }
}

void MeatboyLogic::setVelocityX(float velocityX2) {
    MeatboyLogic::velocityX = velocityX2;
}

void MeatboyLogic::setVelocityY(float velocityY2) {
    MeatboyLogic::velocityY = velocityY2;
}

bool MeatboyLogic::getJumpChecker() {
    return jumpChecker;
}

bool MeatboyLogic::getOnGround() {
    return onGround;
}

WallLogic::WallLogic(World &w, float x, float y, float width, float height) : EntityLogic(w){
    locationXY.first = x;
    locationXY.second = y;
    sizeXY.first = width;
    sizeXY.second = height;
}

void WallLogic::update() {
    updateListObserver();
}

EndgoalLogic::EndgoalLogic(World &w, float x, float y, float width, float height) : EntityLogic(w){
    locationXY.first = x;
    locationXY.second = y;
    sizeXY.first = width;
    sizeXY.second = height;
}

void EndgoalLogic::update() {
    updateListObserver();
}

SpikeLogic::SpikeLogic(World &w, float x, float y, float width, float height, bool isDynamic, float x2, float y2) : EntityLogic(w){
    locationXY.first = x;
    locationXY.second = y;
    sizeXY.first = width;
    sizeXY.second = height;
    dynamicSpike = isDynamic;
    start.first = x;
    start.second = y;

    if(isDynamic){
        pair<int,int> x1y1;
        x1y1.first = locationXY.first;
        x1y1.second = locationXY.second;
        pairs.push_back(x1y1);

        pair<int,int> x2y2;
        x2y2.first = x2;
        x2y2.second = y2;
        pairs.push_back(x2y2);
        if(x1y1.first < x2y2.first){ // platform needs to start moving right
            nowRight = true;
        } else if(x1y1.first > x2y2.first){
            nowLeft = true; // moving left
        }
        if(x1y1.second < x2y2.second){ // platform needs to start moving up
            nowUp = true;
        } else if (x1y1.second > x2y2.second){
            nowDown = true; // moving down
        }
    } else{
        pair<int,int> x1y1;
        x1y1.first = 0;
        x1y1.second = 0;
        pairs.push_back(x1y1);

        pair<int,int> x2y2;
        x2y2.first = 0;
        x2y2.second = 0;
        pairs.push_back(x2y2);
    }

}

void SpikeLogic::moveSpike() {
    if(nowRight){
        locationXY.first += 2;
        if(locationXY.first >= pairs[1].first){
            nowRight = false;
            nowLeft = true;
        }
    }
    if(nowLeft){
        locationXY.first -= 2;
        if(locationXY.first <= start.first){ // move spike to left
            nowLeft = false;
            nowRight = true;
        }
    }

    if(nowUp){
        locationXY.second += 2;
        if(locationXY.second >= pairs[1].second){
            nowDown = true;
            nowUp = false;
        }
    }

    if(nowDown){
        locationXY.second -= 2;
        if(locationXY.second <= start.second){
            nowUp = true;
            nowDown = false;
        }
    }
}

void SpikeLogic::update() {
    updateListObserver();
}

bool SpikeLogic::isDynamic() {
    return dynamicSpike;
}




