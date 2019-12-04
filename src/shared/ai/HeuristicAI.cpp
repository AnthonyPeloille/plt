
#include <engine/AttackCommand.h>
#include <engine/Engine.h>
#include <engine/MoveCommand.h>
#include "HeuristicAI.h"

ai::HeuristicAI::HeuristicAI(const state::State &state, int randomSeed) :AI(state){
    this->randgen.seed(randomSeed);
    this->monstersMap.init(state.getWall(),state.getMonsters(),*dynamic_cast<state::MainCharacter*>(state.getChars()[0].get()),state.getExit());
}

const ai::PathMap &ai::HeuristicAI::getMonstersMap() const {
    return this->monstersMap;
}

void ai::HeuristicAI::stateChanged(const state::Event &event) {

}

void ai::HeuristicAI::run(engine::Engine &engine, state::MainCharacter &character) {
    this->monstersMap.init(engine.getState().getWall(),engine.getState().getMonsters(),character,engine.getState().getExit());
    std::uniform_int_distribution<int> commandes(0,1);
    std::uniform_int_distribution<int> directions(0,3);
    auto queue = this->monstersMap.getQueue();
    int commande = commandes(this->randgen);
    if(commande == 0){
        Point point = queue.top();
        auto* move = new engine::MoveCommand(
                &character, new state::Coords(point.getCoord().getX(),point.getCoord().getY()));
        engine.addCommand(1, move);
    }else{
        auto* attack = new engine::AttackCommand(&character);
        engine.addCommand(0,attack);
    }
}
