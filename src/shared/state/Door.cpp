#include "Door.h"

state::Door::Door() {
    Element::setTypeId(state::DOOR);
}

state::Element* state::Door::clone() {
    return new state::Door(*this);
}

const state::TypeId state::Door::getTypeId() {
    return Element::getTypeId();
}

bool state::Door::isOpened() {
    return statusDoor;
}

bool state::Door::getStatusDoor() const {
    return statusDoor;
}

void state::Door::setStatusDoor(bool statusDoor) {
    this->statusDoor = statusDoor;
}

