#include <state/Space.h>
#include <iostream>
#include <state/StateEvent.h>
#include "CommandTypeId.h"
#include "PathCommand.h"

engine::PathCommand::PathCommand(state::Coords *pos):pos(pos){

}

engine::CommandTypeId engine::PathCommand::getTypeId() const {
    return HANDLE_COLLISIONS;
}

void engine::PathCommand::execute(state::State &state) {
    state::StateEvent event(state::GRID_CHANGED);
    if(state.getWall().get(pos->getY()+1,pos->getX()) == NULL){
        dynamic_cast<state::Space *>(state.getFloor().get(pos->getY()+1,pos->getX()))->setColored(true);
    }
    if(state.getWall().get(pos->getY()-1,pos->getX()) == NULL){
        dynamic_cast<state::Space *>(state.getFloor().get(pos->getY()-1,pos->getX()))->setColored(true);
    }
    if(state.getWall().get(pos->getY(),pos->getX()+1) == NULL){
        dynamic_cast<state::Space *>(state.getFloor().get(pos->getY(),pos->getX()+1))->setColored(true);
    }
    if(state.getWall().get(pos->getY(),pos->getX()-1) == NULL){
        dynamic_cast<state::Space *>(state.getFloor().get(pos->getY(),pos->getX()-1))->setColored(true);
    }
    state.notifyObserver(event);
}

void engine::PathCommand::serialize(Json::Value& out) const {

}