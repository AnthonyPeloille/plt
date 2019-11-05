
#include "MoveCharCommand.h"

engine::MoveCharCommand::MoveCharCommand(int c) :character(c){

}

engine::CommandTypeId engine::MoveCharCommand::getTypeId() const {
    return HANDLE_COLLISIONS;
}

void engine::MoveCharCommand::execute(state::State &state) {

}