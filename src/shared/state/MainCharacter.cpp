

#include "MainCharacter.h"

state::MainCharacter::MainCharacter() {
    Element::setTypeId(state::MC);
}

state::Element* state::MainCharacter::clone() {
    return new state::MainCharacter(*this);
}

const state::TypeId state::MainCharacter::getTypeId() {
    return Element::getTypeId();
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

