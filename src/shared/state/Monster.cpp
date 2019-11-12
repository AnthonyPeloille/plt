

#include "Monster.h"
#include "MainCharacter.h"

state::Monster::Monster(MonsterTypeId id) {
    Element::setTypeId(state::MONSTER);
    monsterTypeId = id;
}

state::Element* state::Monster::clone() {
    return new state::Monster(*this);
}

const state::TypeId state::Monster::getTypeId() {
    return Element::getTypeId();
}

state::MonsterTypeId state::Monster::getMonsterTypeId() const {
    return monsterTypeId;
}

void state::Monster::setMonsterTypeId(MonsterTypeId monsterTypeId) {
    this->monsterTypeId = monsterTypeId;
}

int state::Monster::getHealthPoints() const {
    return HealthPoints;
}

void state::Monster::setHealthPoints(int HealthPoints) {
    if(HealthPoints <= 0){
        this->HealthPoints = 0;
    }else {
        this->HealthPoints = HealthPoints;
    }
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

void state::Monster::attack(state::MainCharacter &target) {

}

void state::Monster::attacked(state::MainCharacter &attacker) {
    this->setHealthPoints(this->getHealthPoints()-attacker.getAttack());
}

