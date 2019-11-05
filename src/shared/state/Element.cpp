
#include "Element.h"

state::Element::Element() {

}

state::Element::~Element() {

}

const state::TypeId state::Element::getTypeId() {
    return this->typeId;
}

void state::Element::setTypeId(state::TypeId typeId) {
    this->typeId = typeId;
}
