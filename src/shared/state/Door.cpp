#include "Door.h"

state::Door::Door() {
    Element::setTypeId(state::DOOR);
}

const state::TypeId state::Door::getTypeId() {
    return Element::getTypeId();
}

bool const state::Door::equals(const Element &other) {
    return Element::equals(other);
}

bool const state::Door::isSpace() {
    return false;
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

