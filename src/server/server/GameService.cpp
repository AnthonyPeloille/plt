
#include "GameService.h"

server::GameService::GameService(Game &game) : AbstractService("game"), game(game){

}

server::HttpStatus server::GameService::get(Json::Value &out, int id) const {
    if(game.getPlayers().size() != 0){
        for ( int index = 0; index < game.getPlayers().size(); ++index ){
            out["players"][index] = game.getPlayers()[index].name;
        }
        return OK;
    }else{
        return NOT_FOUND;
    }
}
