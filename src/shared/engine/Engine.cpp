
#include "Engine.h"

engine::Engine::Engine() {

}

engine::Engine::~Engine() {

}

const state::State &engine::Engine::getState() const {
    return this->currentState;
}

void engine::Engine::addPassiveCommands() {

}

void engine::Engine::addCommand(int priority, Command *cmd) {

}

void engine::Engine::update() {

}
