//
// Created by marcel on 09/07/2023.
//

#include "ConcreteFactory.h"


ConcreteFactory::ConcreteFactory(RenderWindow &window2) : window(window2){

}

shared_ptr<MeatboyLogic> ConcreteFactory::create_meatboy(World &w, float x, float y) {
    shared_ptr<MeatboyLogic> meatboyL = make_shared<MeatboyLogic>(w,x,y);
    new MeatBoy(*meatboyL, window);
    return meatboyL;
}

shared_ptr<WallLogic> ConcreteFactory::create_wall(World& w, float x, float y, float width, float height) {
    shared_ptr<WallLogic> wallL = make_shared<WallLogic>(w,x,y,width,height);
    new Wall(*wallL, window);
    return wallL;
}

shared_ptr<EndgoalLogic> ConcreteFactory::create_endgoal(World &w, float x, float y, float width, float height) {
    shared_ptr<EndgoalLogic> end = make_shared<EndgoalLogic>(w,x,y,width,height);
    new EndGoal(*end, window);
    return end;
}

shared_ptr<SpikeLogic> ConcreteFactory::create_spike(World &w, float x, float y, float width, float height, bool isDynamic, float x2, float y2) {
    shared_ptr<SpikeLogic> spike = make_shared<SpikeLogic>(w,x,y,width,height, isDynamic, x2, y2);
    new Spike(*spike, window);
    return spike;

}



