

#include "MainCharacter.h"

state::MainCharacter::MainCharacter() {
    Element::setTypeId(state::MC);
    Status = MC_ALIVE;
}

bool const state::MainCharacter::isMC() {
    return true;
}

const state::TypeId state::MainCharacter::getTypeId() {
    return Element::getTypeId();
}

bool const state::MainCharacter::equals(const Element &other) {
    return MobileElement::equals(other);
}

state::McStatus state::MainCharacter::getStatus() const {
    return Status;
}

void state::MainCharacter::setStatus(McStatus Status) {
    this->Status = Status;
}

int state::MainCharacter::getHealthPoints() const {
    return HealthPoints;
}

void state::MainCharacter::setHealthPoints(int HealthPoints) {
    this->HealthPoints = HealthPoints;
}

int state::MainCharacter::getDefense() const {
    return Defense;
}

void state::MainCharacter::setDefense(int Defense) {
    this->Defense = Defense;
}

int state::MainCharacter::getAttack() const {
    return Attack;
}

void state::MainCharacter::setAttack(int Attack) {
    this->Attack = Attack;
}

