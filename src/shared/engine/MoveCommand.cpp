
#include <state/StateEvent.h>
#include <state/Space.h>
#include "MoveCommand.h"

engine::MoveCommand::~MoveCommand() {}

engine::MoveCommand::MoveCommand(state::MainCharacter* c, state::Coords* pos) : character(c), pos(pos){

}

engine::CommandTypeId engine::MoveCommand::getTypeId() const {
    return MOVE_CHAR;
}

void engine::MoveCommand::execute(state::State &state) {
    /*state::StateEvent event(state::MC_CHANGED);
    state::Coords pos = this->character->getPosition();
    switch(this->character->getDirection()){
        case state::NORTH:
            pos.setY(pos.getY()-1);
            break;
        case state::SOUTH:
            pos.setY(pos.getY()+1);
            break;
        case state::EAST:
            pos.setX(pos.getX()+1);
            break;
        case state::WEST:
            pos.setX(pos.getX()-1);
            break;
        default:
            break;
    }
    this->character->setPosition(pos);*/
    if(!this->character->getIsFighting()){
        state::StateEvent event(state::MC_CHANGED);
        auto* old_pos = &this->character->getPosition();
        if(state.getWall().get(old_pos->getY()+1,old_pos->getX()) == NULL){
            dynamic_cast<state::Space *>(state.getFloor().get(old_pos->getY()+1,old_pos->getX()))->setColored(false);
        }
        if(state.getWall().get(old_pos->getY()-1,old_pos->getX()) == NULL){
            dynamic_cast<state::Space *>(state.getFloor().get(old_pos->getY()-1,old_pos->getX()))->setColored(false);
        }
        if(state.getWall().get(old_pos->getY(),old_pos->getX()+1) == NULL){
            dynamic_cast<state::Space *>(state.getFloor().get(old_pos->getY(),old_pos->getX()+1))->setColored(false);
        }
        if(state.getWall().get(old_pos->getY(),old_pos->getX()-1) == NULL){
            dynamic_cast<state::Space *>(state.getFloor().get(old_pos->getY(),old_pos->getX()-1))->setColored(false);
        }
        //this->character->setPosition(*this->pos);
        if((this->pos->getY() == old_pos->getY()+1) || (this->pos->getY() == old_pos->getY()-1) || (this->pos->getY() == old_pos->getY())){
            if((this->pos->getX() == old_pos->getX()+1) || (this->pos->getX() == old_pos->getX()-1) || (this->pos->getX() == old_pos->getX())){
                if(state.getWall().get(this->pos->getY(),this->pos->getX()) == NULL){
                    this->character->setPosition(*this->pos);
                    for(auto monster : state.getMonsters()) {
                        //std::cout << (std::abs(monster->getPosition().getX() - this->character->getPosition().getX()) + std::abs(monster->getPosition().getY() - this->character->getPosition().getY())) <<std::endl;
                        if ((std::abs(monster->getPosition().getX() - this->character->getPosition().getX()) +
                             std::abs(monster->getPosition().getY() - this->character->getPosition().getY())) <= 1) {
                            this->character->setIsFighting(true);
                        }
                    }
                }
            }
        }
        state.notifyObserver(event);
    }
}

void engine::MoveCommand::serialize(Json::Value& out) const {
    Json::Value newCmd;
    newCmd["CommandTypeId"] = MOVE_CHAR;
    newCmd["TypeId"] = this->character->getTypeId();
    newCmd["PositionX"] = this->pos->getX();
    newCmd["PositionY"] = this->pos->getY();
}