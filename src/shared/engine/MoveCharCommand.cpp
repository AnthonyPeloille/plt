
#include "MoveCharCommand.h"
#include "state/Direction.h"

engine::MoveCharCommand::MoveCharCommand(state::MainCharacter* c) :character(c){

}

engine::CommandTypeId engine::MoveCharCommand::getTypeId() const {
    return HANDLE_COLLISIONS;
}

void engine::MoveCharCommand::execute(state::State &state) {
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
    this->character->setPosition(pos);
}