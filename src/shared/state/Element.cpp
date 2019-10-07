
#include "Element.h"

state::Element::Element() {

}

state::Element::~Element() {

}

const state::TypeId state::Element::getTypeId() {
    return this->typeId;
}

bool const state::Element::equals(const Element &other) {
    return 0;
}

int state::Element::getX() const {
    return x;
}

int state::Element::getY() const {
    return y;
}

void state::Element::setX(int x) {
    this->x = x;
}

void state::Element::setY(int y) {
    this->y = y;
}

void state::Element::setTypeId(state::TypeId typeId) {
    this->typeId = typeId;
}
