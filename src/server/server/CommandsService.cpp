
#include <engine/MoveCommand.h>
#include "CommandsService.h"

server::CommandsService::CommandsService(Game &game) : AbstractService("commands"), game(game){

}

server::HttpStatus server::CommandsService::get(Json::Value &out, int id) const {
    return NOT_IMPLEMENTED;
}

server::HttpStatus server::CommandsService::put(Json::Value &out, const Json::Value &in) {
    if(in["CommandTypeId"].asInt() == engine::MOVE_CHAR) {
        auto move = new engine::MoveCommand();
        this->game.getEngine().addCommand(0, move);
    }
    this->game.run();
    return CREATED;
}
