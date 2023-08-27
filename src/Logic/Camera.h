//
// Created by marcel on 27/11/2022.
//

#ifndef PROJECTAP_CAMERA_H
#define PROJECTAP_CAMERA_H

#include "iostream"
using namespace std;
class EntityLogic;

class Camera {

public:
    ///getter windowHeight
    float getWindowHeight() const;
    ///getter cameraHeight
    float getCameraHeight() const;
    ///setter automatic
    void setAutomatic(bool a);
    ///getter automatic
    bool getAutomatic();

    Camera(float w,float h);
    ///convert logix cooordinates -> pixel coordinates
    pair<float,float> convertLogicToPixel(float x, float y, const EntityLogic& entity) const;
    ///moves the camera up
    void cameraGoUp(float a);

private:
    float windowHeight;

    float windowWidth;

    float cameraHeight;

    bool goUp;

    bool automatic;
};


#endif //PROJECTAP_CAMERA_H
