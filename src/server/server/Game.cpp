
#include "Game.h"

server::Game::Game() {
    this->engine.init("../res/map.txt","../res/wall.txt");
}

server::Player &server::Game::player(int i) {
    return players[i];
}

const std::vector<server::Player> &server::Game::getPlayers() const {
    return this->players;
}

void server::Game::setPlayers(const std::vector<Player> &players) {
    this->players = players;
}

void server::Game::run() {
    this->engine.update();
}

engine::Engine &server::Game::getEngine() {
    return this->engine;
}
