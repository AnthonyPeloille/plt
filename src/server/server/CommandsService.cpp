
#include <engine/MoveCommand.h>
#include "CommandsService.h"

server::CommandsService::CommandsService(Game &game) : AbstractService("commands"), game(game){

}

server::HttpStatus server::CommandsService::get(Json::Value &out, int id) const {
    return NOT_IMPLEMENTED;
}

server::HttpStatus server::CommandsService::put(Json::Value &out, const Json::Value &in) {
    state::Coords pos = this->game.getEngine().getState().getChars()[0].get()->getPosition();
    pos.setY(pos.getY()+1);
    auto move = new engine::MoveCommand(
            dynamic_cast<state::MainCharacter *>(this->game.getEngine().getState().getChars()[0].get()),&pos);
    this->game.getEngine().addCommand(0,move);
    this->game.run();
    return CREATED;
}
