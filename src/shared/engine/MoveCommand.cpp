
#include <state/StateEvent.h>
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
    state::StateEvent event(state::MC_CHANGED);
    this->character->setPosition(*this->pos);
    state.notifyObserver(event);
}