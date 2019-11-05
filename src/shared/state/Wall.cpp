

#include "Wall.h"

state::Wall::Wall(WallTypeId id) {
    Element::setTypeId(state::WALL);
    wallTypeId = id;
}

state::Element* state::Wall::clone() {
    return new state::Wall(*this);
}

const state::TypeId state::Wall::getTypeId() {
    return Element::getTypeId();
}

state::WallTypeId state::Wall::getWallTypeId() const {
    return wallTypeId;
}

void state::Wall::setWallTypeId(WallTypeId wallTypeId) {
    this->wallTypeId = wallTypeId;
}

