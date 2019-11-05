

#include "Space.h"

state::Space::Space(SpaceTypeId id) {
    Element::setTypeId(state::SPACE);
    spaceTypeId = id;
}

state::Element* state::Space::clone() {
    return new state::Space(*this);
}

const state::TypeId state::Space::getTypeId() {
    return Element::getTypeId();
}

const state::SpaceTypeId state::Space::getSpaceTypeId() {
    return spaceTypeId;
}

void state::Space::setSpaceTypeId(SpaceTypeId spaceTypeId) {
    this->spaceTypeId = spaceTypeId;
}

