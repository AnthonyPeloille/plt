#include "Chest.h"

state::Chest::Chest(ChestContentId id) {
    chestContentId = id;
    Element::setTypeId(state::CHEST);
}

bool const state::Chest::isSpace() {
    return 0;
}

const state::TypeId state::Chest::getTypeId() {
    return Element::getTypeId();
}

bool const state::Chest::equals(const Element &other) {
    return Element::equals(other);
}

bool state::Chest::isOpened() {
    return this->statusChest;
}

state::ChestContentId state::Chest::getChestContentId() const {
    return this->chestContentId;
}

void state::Chest::setChestContentId(ChestContentId chestContentId) {
    this->chestContentId = chestContentId;
}

bool state::Chest::getStatusChest() const {
    return statusChest;
}

void state::Chest::setStatusChest(bool statusChest) {
    this->statusChest = statusChest;
}
