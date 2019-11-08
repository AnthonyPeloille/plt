
#include "Engine.h"

engine::Engine::Engine() {
    this->currentState = state::State();
    std::string map = "../res/map.txt";
    currentState.initFloor(map,80,45);
    std::string wall = "../res/wall.txt";
    currentState.initWall(wall,80,45);
    currentState.initChars(wall,80,45);
}

engine::Engine::~Engine() = default;

const state::State &engine::Engine::getState() const {
    return this->currentState;
}

void engine::Engine::addPassiveCommands() {

}

void engine::Engine::addCommand(int priority, Command *cmd) {
    currentCommands[priority] = std::move(std::unique_ptr<Command>(cmd));
}

void engine::Engine::update() {

    //std::map<int, std::unique_ptr<Command>>::iterator it;

    for (auto it = currentCommands.begin(); it != currentCommands.end(); ++it) {
        it->second->execute(currentState);
    }
    /*
    for(size_t i=0;i<currentCommands.size();i++){
        currentCommands[i]->execute(currentState);
    }*/
    currentCommands.clear();
}
