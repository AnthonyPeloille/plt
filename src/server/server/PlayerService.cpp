
#include "PlayerService.h"

server::PlayerService::PlayerService(Game &game)
        : AbstractService("player"), game(game) {
}

server::HttpStatus server::PlayerService::get(Json::Value &out, int id) const {
    if(game.getPlayers().size() != 0 && id < game.getPlayers().size()){
        out["name"] = game.player(id).name;
        return OK;
    }else{
        return NOT_FOUND;
    }
}

server::HttpStatus server::PlayerService::post(const Json::Value &in, int id) {
    return NOT_IMPLEMENTED;
}

server::HttpStatus server::PlayerService::put(Json::Value &out, const Json::Value &in) {
    std::vector<Player> players = game.getPlayers();
    Player player;
    player.name = in["name"].asString();
    players.push_back(player);
    game.setPlayers(players);
    return CREATED;
}

server::HttpStatus server::PlayerService::remove(int id) {
    return NOT_IMPLEMENTED;
}
