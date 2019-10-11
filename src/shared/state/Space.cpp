

#include "Space.h"

state::Space::Space(SpaceTypeId id) {
    Element::setTypeId(state::SPACE);
    spaceTypeId = id;
}

bool const state::Space::isSpace() {
    return true;
}

const state::TypeId state::Space::getTypeId() {
    return Element::getTypeId();
}

bool const state::Space::equals(const Element &other) {
    return Element::equals(other);
}

const state::SpaceTypeId state::Space::getSpaceTypeId() {
    return spaceTypeId;
}

void state::Space::setSpaceTypeId(SpaceTypeId spaceTypeId) {
    this->spaceTypeId = spaceTypeId;
}

