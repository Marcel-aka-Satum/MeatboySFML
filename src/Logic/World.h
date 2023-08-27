//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_WORLD_H
#define PROJECTAP_WORLD_H

#include "AbstractWindow.h"
#include "EntityLogic.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Camera.h"
#include "StopWatch.h"
enum SuccessEnum { ImportAborted, PartialImport, Success };
using namespace sf;
using namespace std;

class AbstractFactory;

///World Class that will store everything World needs to have
class World {
private:
    AbstractFactory& abstract_factory;
    AbstractWindow& logic_window;
    shared_ptr<MeatboyLogic> meatboy;
    vector<shared_ptr<WallLogic>> walls;
    vector<shared_ptr<SpikeLogic>> spikes;
    shared_ptr<EndgoalLogic> endgoal;
    bool gameIsPlaying;
    bool nextLVL;
    shared_ptr<StopWatch> stopwatch = stopwatch->getStopWatch();
    Camera camera;
public:
    /***
     * Create new game world
     *
     * */
    World(AbstractFactory& abstract_factory, AbstractWindow& logic_window);

    /***
     * Game loop
     * */
    void gameLoop();

    /**
     * Update function that updates the world
     * */
    bool update();
    /**
      * createWall function that makes a wall with given arguments
      * */
    void createWall(float x, float y, float width2, float height2);
    /**
      * createPlayer function that creates a player with given arguments
      * */
    void createPlayer(float x, float y);
    /**
      * createEndgoal function that creates an endgoal with given arguments
      * */
    void createEndgoal(float x, float y, float width2, float height2);
    /**
      * createSpike function that creates a spike with given arguments
      * */
    void createSpike(float x, float y, float width2, float height2, bool isDynamic, float x2, float y2);
    /**
      * getter for camera object
      * */
    Camera &getCamera();
    /**
      * getter for nextLVL var
      * */
    bool getNextLVL();
    /**
      * getter for Stopwatch object
      * */
    shared_ptr<StopWatch> getStopwatch();
    /**
      * XML parser initialiser
      * */
    SuccessEnum init(const char* inputFile);

};


#endif //PROJECTAP_WORLD_H
