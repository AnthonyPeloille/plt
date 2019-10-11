

#include "MobileElement.h"

state::MobileElement::MobileElement() {
    direction = NONE;
}

bool const state::MobileElement::equals(const Element &other) {
    return Element::equals(other);
}

bool const state::MobileElement::isStatic() {
    return false;
}

state::Direction state::MobileElement::getDirection() const {
    return direction;
}

void state::MobileElement::setDirection(Direction direction) {
    this->direction = direction;
}

int state::MobileElement::getSpeed() const {
    return speed;
}

void state::MobileElement::setSpeed(int speed) {
    this->speed = speed;
}

int state::MobileElement::getPosition() const {
    return position;
}

void state::MobileElement::setPosition(int position) {
    this->position = position;
}

