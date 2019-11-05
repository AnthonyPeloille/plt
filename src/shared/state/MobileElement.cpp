

#include "MobileElement.h"

state::MobileElement::MobileElement() {
    direction = NONE;
}

bool const state::MobileElement::isStatic() {
    return false;
}

state::Direction state::MobileElement::getDirection() const {
    return this->direction;
}

void state::MobileElement::setDirection(Direction direction) {
    this->direction = direction;
}

int state::MobileElement::getSpeed() const {
    return this->speed;
}

void state::MobileElement::setSpeed(int speed) {
    this->speed = speed;
}

const state::Coords& state::MobileElement::getPosition() const {
    return this->position;
}

void state::MobileElement::setPosition(const Coords& position) {
    this->position = position;
}

