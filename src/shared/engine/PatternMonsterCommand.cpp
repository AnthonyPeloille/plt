#include <state/StateEvent.h>
#include <state/Space.h>
#include "PatternMonsterCommand.h"

engine::PatternMonsterCommand::PatternMonsterCommand(state::Monster m) : monster(m){

}

engine::CommandTypeId engine::PatternMonsterCommand::getTypeId() const {
    return PATTERN_MONSTER;
}

void engine::PatternMonsterCommand::execute(state::State &state) {
    state::StateEvent event(state::MONSTER_CHANGED);
    auto posMonster = this->monster.getPosition();
    if (compteur%4==0){
        this->pos.setX(posMonster.getX()+1);
        this->pos.setY(posMonster.getY());
    }
    else if (compteur%4==1){
        this->pos.setX(posMonster.getX());
        this->pos.setY(posMonster.getY()+1);
    }
    else if (compteur%4==2){
        this->pos.setX(posMonster.getX()-1);
        this->pos.setY(posMonster.getY());
    }
    else if (compteur%4==3){
        this->pos.setX(posMonster.getX());
        this->pos.setY(posMonster.getY()-1);
    }
    if(state.getWall().get(this->pos.getY(),this->pos.getX()) == NULL) {
        this->monster.setPosition(this->pos);
    }
    this->compteur++;
    state.notifyObserver(event);
}

void engine::PatternMonsterCommand::serialize(Json::Value &out) const{
    Json::Value newCmd;
    newCmd["CommandTypeId"] = PATTERN_MONSTER;
    newCmd["Character"] = "Monster";
    newCmd["PositionX"] = this->pos.getX();
    newCmd["PositionY"] = this->pos.getY();
    out = newCmd;
}

void engine::PatternMonsterCommand::unserialize(Json::Value &in, state::State &state) {

}
