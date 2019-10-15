

#include "Wall.h"

state::Wall::Wall(WallTypeId id) {
    Element::setTypeId(state::WALL);
    wallTypeId = id;
}

state::Element* state::Wall::clone() {
    return new state::Wall(*this);
}

bool const state::Wall::isSpace() {
    return false;
}

const state::TypeId state::Wall::getTypeId() {
    return Element::getTypeId();
}

bool const state::Wall::equals(const Element &other) {
    return Element::equals(other);
}

state::WallTypeId state::Wall::getWallTypeId() const {
    return wallTypeId;
}

void state::Wall::setWallTypeId(WallTypeId wallTypeId) {
    this->wallTypeId = wallTypeId;
}

