//
// Created by marcel on 27/11/2022.
//

#include "Camera.h"
#include "EntityLogic.h"

Camera::Camera(float w, float h) {
    windowHeight = h;
    windowWidth = w;
    cameraHeight = 0;
    goUp = false;
}

pair<float, float> Camera::convertLogicToPixel(float x, float y, const EntityLogic &entity) const {
    pair<float, float> newPosition(x, (windowHeight - ((y + entity.getYSize()) - cameraHeight)));
    return newPosition;
}

float Camera::getWindowHeight() const {
    return windowHeight;
}


float Camera::getCameraHeight() const {
    return cameraHeight;
}

void Camera::cameraGoUp(float a) {
    cameraHeight += a;
}

void Camera::setAutomatic(bool a) {
    automatic = a;
}

bool Camera::getAutomatic() {
    return automatic;
}
