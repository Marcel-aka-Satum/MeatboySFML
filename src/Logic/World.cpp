//
// Created by marcel on 27/11/2022.
//

#include "World.h"
#include "AbstractFactory.h"
#include "../../Parser/tinyxml.h"
#include "fstream"


World::World(AbstractFactory &abstract_factory1, AbstractWindow &logic_window1) : abstract_factory(abstract_factory1), logic_window(logic_window1),
                                                                                  camera(Camera(logic_window.getWindowWidth(), logic_window.getWindowHeight())) {
    nextLVL = false;
    gameIsPlaying = false;
}


void World::gameLoop() {
    /*
     * if the window is open do the following:
     * 1. clear the screen
     * 2. display all the data the window has
     * 3. check if the screen needs to be closed if so end the loop
     * */
    gameIsPlaying = true;
    while(logic_window.isOpen() && gameIsPlaying){
        logic_window.clear();
        logic_window.draw();
        gameIsPlaying = update();
        logic_window.display();
        logic_window.checkClose();
    }

}

bool World::update() {
    stopwatch->nextFrame();

    meatboy->checkCollisionWalls(walls);
    if(meatboy->checkCollision(*meatboy, *endgoal)){ // the player has reached the endgoal so go to the next lvl if there is one
        nextLVL = true;
        return false;
    }

    //update observers
    meatboy->update();
    endgoal->update();

    for(auto i : walls){
        i->update();
    }
    for(auto i : spikes){
        if(i->isDynamic()){
            i->moveSpike();
        }
        i->update();
    }

    //if a player hits the spike restart lvl
    for(auto i : spikes){
        if(meatboy->checkCollision(*meatboy, *i)){
            return false;
        }
    }

    //if a player falls down beyong camer sight restart the lvl
    if(meatboy->getYLocation() + meatboy->getYSize() < camera.getCameraHeight()){
        return false;
    }

    //check keyboard inputs to move player if needed
    char key[4] = {-1, -1, -1, -1};
    logic_window.key_board_press(key);
    if(key[0] == 'A' && !meatboy->isCollisionLeft()){
        meatboy->SetMovingLeft(true);
        if(meatboy->isCollisionRight()){
            meatboy->setCollisionRight(false);
        }
        meatboy->moveLeft();
    }
    if(key[1] == 'D' && !meatboy->isCollisionRight()){
        meatboy->SetMovingRight(true);
        if(meatboy->isCollisionLeft()){
            meatboy->setCollisionLeft(false);
        }
        meatboy->moveRight();
    }
    if(key[2] == 'W' && meatboy->getJumpChecker()){
        meatboy->setIsJumping(true);
        if(meatboy->isCollisionLeft()){
            meatboy->setVelocityX(5);
            meatboy->setVelocityY(1);
        } else if(meatboy->isCollisionRight()){
            meatboy->setVelocityX(-5);
            meatboy->setVelocityY(1);
        }
        meatboy->jump();
        meatboy->setCollisionBottom(false);
        meatboy->setGroundHeight(0);
    }
    if(key[3] == 'E'){
        return false;
    }

    //slowdown meatboy
    if(key[0] == -1 && key[1] == -1 && key[2] == -1){
        meatboy->slowDown();
    }

    if(meatboy->getOnGround() || meatboy->getYLocation() + meatboy->getYSize() > meatboy->getYSize()){
        //falldown meatboy
        if(meatboy->getYLocation() > 0){
            meatboy->downJump();
        }
    }

    if(meatboy->getYLocation() >= camera.getCameraHeight() + camera.getWindowHeight() * 0.8){
        float heightDiff = abs((camera.getCameraHeight() + camera.getWindowHeight() *0.8) - meatboy->getYLocation());
        camera.cameraGoUp(heightDiff);
    }

    //automatic camera and player has started jumping
    if(camera.getAutomatic() && meatboy->getYLocation() > 1){
        camera.cameraGoUp(0.6);
    }

    return true;
}

Camera &World::getCamera(){
    return camera;
}

shared_ptr<StopWatch> World::getStopwatch() {
    return stopwatch;
}

bool World::getNextLVL() {
    return nextLVL;
}

SuccessEnum World::init(const char *inputFile) {
    SuccessEnum endResult = Success;
    TiXmlDocument doc;
    ofstream errStream;
    if(!doc.LoadFile(inputFile)) {
        errStream << "XML IMPORT ABORTED: " << doc.ErrorDesc() << endl;
        return endResult;
    }
    TiXmlElement* root = doc.FirstChildElement();
    if(root == nullptr) {
        errStream << "XML PARTIAL IMPORT: Failed to load file: No root element." << std::endl;
        endResult = PartialImport;
        doc.Clear();
        return endResult;
    }

    for(TiXmlElement* elem = root->FirstChildElement(); elem != nullptr; elem = elem->NextSiblingElement()){
        string container = elem->Value();
        string testRoot = root->Value();
        if(container == "PLAYER"){
            float tempPositieX, tempPositieY;
            for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr; j = j->NextSiblingElement()){
                string elemName = j->Value();
                if(elemName == "positieX"){
                    tempPositieX = stof(j->GetText());
                } else if(elemName == "positieY"){
                    tempPositieY = stof(j->GetText());
                } else{
                    errStream << "XML PARTIAL IMPORT: INCORRECT NAME FOR PLAYER" << std::endl;
                    endResult = PartialImport;
                    return endResult;
                }
            }
            createPlayer(tempPositieX, tempPositieY);
        } else if(container == "WALL"){
            float tempPositieX, tempPositieY, tempWidth, tempHeight;
            for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;j = j->NextSiblingElement()) {
                string elemName = j->Value();
                if(elemName == "positieX"){
                    tempPositieX = stof(j->GetText());
                } else if(elemName == "positieY"){
                    tempPositieY = stof(j->GetText());
                } else if(elemName == "width"){
                    tempWidth = stof(j->GetText());
                } else if(elemName == "height"){
                    tempHeight = stof(j->GetText());
                } else{
                    errStream << "XML PARTIAL IMPORT: INCORRECT NAME FOR WALL" << std::endl;
                    endResult = PartialImport;
                    return endResult;
                }
            }
            createWall(tempPositieX,tempPositieY,tempWidth,tempHeight);
        } else if(container == "ENDGOAL"){
            float tempPositieX, tempPositieY, tempWidth, tempHeight;
            for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;j = j->NextSiblingElement()) {
                string elemName = j->Value();
                if(elemName == "positieX"){
                    tempPositieX = stof(j->GetText());
                } else if(elemName == "positieY"){
                    tempPositieY = stof(j->GetText());
                } else if(elemName == "width"){
                    tempWidth = stof(j->GetText());
                } else if(elemName == "height"){
                    tempHeight = stof(j->GetText());
                } else{
                    errStream << "XML PARTIAL IMPORT: INCORRECT NAME FOR WALL" << std::endl;
                    endResult = PartialImport;
                    return endResult;
                }
            }
            createEndgoal(tempPositieX,tempPositieY,tempWidth,tempHeight);
        } else if(container == "SPIKE"){
            float tempPositieX, tempPositieY, tempWidth, tempHeight;
            bool dynamic = false;
            float x2 = 0;
            float y2 = 0;
            for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;j = j->NextSiblingElement()) {
                string elemName = j->Value();
                if(elemName == "positieX"){
                    tempPositieX = stof(j->GetText());
                } else if(elemName == "positieY"){
                    tempPositieY = stof(j->GetText());
                } else if(elemName == "width"){
                    tempWidth = stof(j->GetText());
                } else if(elemName == "height"){
                    tempHeight = stof(j->GetText());
                } else if(elemName == "dynamic"){
                    string tempBool = j->GetText();
                    if(tempBool == "True"){
                        dynamic = true;
                    } else{
                        dynamic = false;
                    }
                } else if(elemName == "x2"){
                    x2 = stof(j->GetText());
                }else if(elemName == "y2"){
                    y2 = stof(j->GetText());
                }else{
                    errStream << "XML PARTIAL IMPORT: INCORRECT NAME FOR WALL" << std::endl;
                    endResult = PartialImport;
                    return endResult;
                }
            }
            createSpike(tempPositieX,tempPositieY,tempWidth,tempHeight, dynamic,x2,y2);
        } else if(container == "CAMERAUTO"){
            bool isAuto = false;
            for(TiXmlElement* j = elem->FirstChildElement(); j != nullptr;j = j->NextSiblingElement()) {
                string elemName = j->Value();
                if(elemName == "isAuto"){
                    string tempBool = j->GetText();
                    if(tempBool == "ON"){
                        isAuto = true;
                    } else{
                        isAuto = false;
                    }
                }
                if(isAuto){
                    camera.setAutomatic(true);
                } else{
                    camera.setAutomatic(false);
                }
            }
        }
    }
    doc.Clear();
    return endResult;
}

void World::createWall(float x, float y, float width2, float height2) {
    shared_ptr<WallLogic> wall = abstract_factory.create_wall(*this, x,y,width2,height2);
    walls.push_back(wall);
}

void World::createPlayer(float x, float y) {
    meatboy = abstract_factory.create_meatboy(*this, x, y);
}

void World::createEndgoal(float x, float y, float width2, float height2) {
    endgoal = abstract_factory.create_endgoal(*this, x,y,width2,height2);
}

void World::createSpike(float x, float y, float width2, float height2, bool isDynamic, float x2, float y2) {
    shared_ptr<SpikeLogic> spike = abstract_factory.create_spike(*this, x,y,width2,height2, isDynamic,x2,y2);
    spikes.push_back(spike);
}
