
#include "Engine.h"
#include "../../../extern/jsoncpp-1.8.0/jsoncpp.cpp"

engine::Engine::Engine() {
    this->currentState = state::State();
}

engine::Engine::~Engine() = default;

void engine::Engine::init(std::string map, std::string walls) {
    currentState.initFloor(map,80,45);
    currentState.initWall(walls,80,45);
    currentState.initChars(walls,80,45);
}

const state::State &engine::Engine::getState() const {
    return this->currentState;
}

void engine::Engine::addPassiveCommands() {

}

void engine::Engine::addCommand(int priority, Command *cmd) {
    //Json::Value newCmd = cmd->serialize();
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
