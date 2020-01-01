
#include <state/StateEvent.h>
#include <iostream>
#include "AttackCommand.h"
#include "state/Monster.h"

engine::AttackCommand::~AttackCommand() {}

engine::AttackCommand::AttackCommand(state::MainCharacter *c) : character(c){

}

engine::CommandTypeId engine::AttackCommand::getTypeId() const {
    return ATTACK;
}

void engine::AttackCommand::execute(state::State &state) {
    state::StateEvent event(state::MC_CHANGED);
    for(auto monster : state.getMonsters()) {
        //std::cout << (std::abs(monster->getPosition().getX() - this->character->getPosition().getX()) + std::abs(monster->getPosition().getY() - this->character->getPosition().getY())) <<std::endl;
        if ((std::abs(monster->getPosition().getX() - this->character->getPosition().getX()) +
             std::abs(monster->getPosition().getY() - this->character->getPosition().getY())) <= 1) {
            dynamic_cast<state::Monster *>(monster.get())->attacked(*this->character);
            if(dynamic_cast<state::Monster *>(monster.get())->getHealthPoints() == 0){
                state.getMonsters().erase(state.getMonsters().begin());
                this->character->setIsFighting(false);
            }
        }
    }
    state.notifyObserver(event);
}

void engine::AttackCommand::serialize(Json::Value& out) const {

}

