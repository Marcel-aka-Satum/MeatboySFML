//
// Created by marcel on 28/11/2022.
//

#ifndef PROJECTAP_ENTITYLOGIC_H
#define PROJECTAP_ENTITYLOGIC_H


#include "Subject.h"
#include <memory>
#include "vector"
using namespace std;

class EntityObserver;
class World;
class WallLogic;

class EntityLogic : public Subject{
protected:
    pair<float,float> sizeXY;
    pair<float,float> locationXY;
    World& world;
    bool collisionLeft = false;
    bool collisionRight = false;
    bool collisionTop = false;
    bool collisionBottom = false;
    float groundHeight = 0.f;
public:

    explicit EntityLogic(World &world);

    virtual void update()=0;
    ///getter xSize
    float getXSize() const;
    ///getter ySize
    float getYSize() const;
    ///getter XLocation
    float getXLocation() const;
    ///getter YLocation
    float getYLocation() const;
    ///getter world object
    World& getWorld();
    ///check collision between 2 entities
    bool checkCollision(EntityLogic& e1, EntityLogic& e2);
    ///checks if Entity has collision from left
    bool isCollisionLeft() const;
    ///checks if Entity has collision from right
    bool isCollisionRight() const;
    ///checks if Entity has collision from top
    bool isCollisionTop() const;
    ///checks if Entity has collision from bottom
    bool isCollisionBottom() const;
    ///setter collision left
    void setCollisionLeft(bool collisionLeft2);
    ///setter collision right
    void setCollisionRight(bool collisionRight2);
    ///setter collision top
    void setCollisionTop(bool collisionTop2);
    ///setter collision bottom
    void setCollisionBottom(bool collisionBottom2);
    ///setter groundheight
    void setGroundHeight(float v);

};

class MeatboyLogic : public EntityLogic{
protected:
    float velocityX;
    float velocityY;
    float gravity;
    float acceleration;
    float maxVelocity;
    float jumpForce;
    bool isJumping;
    bool isMovingRight;
    bool isMovingLeft;
    bool jumpChecker;
    bool onGround;

public:
    explicit MeatboyLogic(World& w, float x, float y);
    ///setter for isJumping
    void setIsJumping(bool v);
    ///setter for velocityX
    void setVelocityX(float velocityX2);
    ///getter for jumpChecker
    bool getJumpChecker();
    ///setter for velocityY
    void setVelocityY(float velocityY2);
    ///getter for onGround
    bool getOnGround();

    /***
     * Function to move meatboy to the left
     * */
    void moveLeft();

    /***
     * Function to move meatboy to the right
     * */
    void moveRight();
    ///setter movingLeft
    void SetMovingLeft(bool a);
    ///setter movingRight
    void SetMovingRight(bool a);
    /// Slows the Meatboy
    void slowDown();
    /// handles falling
    void downJump();

    /***
     * Function to move meatboy upwards
     * */
    void jump();

    void update() override;

    ///checks collisions between Meatboy and Wall
    void checkCollisionWalls(vector<shared_ptr<WallLogic>>& walls);
};

class WallLogic : public EntityLogic{
public:
    explicit WallLogic(World& w, float x, float y, float width, float height);

    void update() override;
};

class EndgoalLogic : public EntityLogic{
public:
    explicit EndgoalLogic(World& w, float x, float y, float width, float height);

    void update() override;
};

class SpikeLogic : public EntityLogic{
private:
    bool dynamicSpike;
    bool nowLeft= false;
    bool nowRight= false;
    bool nowUp = false;
    bool nowDown = false;
    pair<int,int> start;
    vector<pair<int,int>> pairs;
public:
    explicit SpikeLogic(World& w, float x, float y, float width, float height, bool isDynamic, float x2, float y2);

    void update() override;
    ///getter for isDynamic
    bool isDynamic();
    ///moves the spikes if they are dynamic
    void moveSpike();
};



#endif //PROJECTAP_ENTITYLOGIC_H
