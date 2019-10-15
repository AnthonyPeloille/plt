

#include "Monster.h"

state::Monster::Monster(MonsterTypeId id) {
    Element::setTypeId(state::MONSTER);
    monsterTypeId = id;
    Status = ALIVE;
}

state::Element* state::Monster::clone() {
    return new state::Monster(*this);
}

bool const state::Monster::isMC() {
    return false;
}

const state::TypeId state::Monster::getTypeId() {
    return Element::getTypeId();
}

bool const state::Monster::equals(const Element &other) {
    return MobileElement::equals(other);
}

state::MonsterTypeId state::Monster::getMonsterTypeId() const {
    return monsterTypeId;
}

void state::Monster::setMonsterTypeId(MonsterTypeId monsterTypeId) {
    this->monsterTypeId = monsterTypeId;
}

state::MonsterStatus state::Monster::getStatus() const {
    return Status;
}

void state::Monster::setStatus(MonsterStatus Status) {
    this->Status = Status;
}

int state::Monster::getHealthPoints() const {
    return HealthPoints;
}

void state::Monster::setHealthPoints(int HealthPoints) {
    this->HealthPoints = HealthPoints;
}

int state::Monster::getDefense() const {
    return Defense;
}

void state::Monster::setDefense(int Defense) {
    this->Defense = Defense;
}

int state::Monster::getAttack() const {
    return Attack;
}

void state::Monster::setAttack(int Attack) {
    this->Attack = Attack;
}

