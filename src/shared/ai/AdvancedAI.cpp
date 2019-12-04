

#include <engine/AttackCommand.h>
#include <engine/Engine.h>
#include <engine/MoveCommand.h>
#include "AdvancedAI.h"
#include "HeuristicAI.h"

ai::AdvancedAI::AdvancedAI(const state::State &state, int randomSeed) : AI(state) {
    this->randgen.seed(randomSeed);
    this->monstersMap.init(state.getWall(),state.getMonsters(),*dynamic_cast<state::MainCharacter*>(state.getChars()[0].get()));
}

const ai::PathMap &ai::AdvancedAI::getMonstersMap() const {
    return this->monstersMap;
}

void ai::AdvancedAI::stateChanged(const state::Event &event) {

}

void ai::AdvancedAI::run(engine::Engine &engine, state::MainCharacter &character) {
    int depth = 0;
    int updateCount = 0;
    if(depth<this->maxDepth & updateCount<this->maxUpdates){

        updateCount++;
    }else{
        this->monstersMap.init(engine.getState().getWall(),engine.getState().getMonsters(),character);
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
}

int ai::AdvancedAI::getMaxDepth() const {
    return this->maxDepth;
}

void ai::AdvancedAI::setMaxDepth(int maxDepth) {
    this->maxDepth = maxDepth;
}

int ai::AdvancedAI::getMaxUpdates() const {
    return this->maxUpdates;
}

void ai::AdvancedAI::setMaxUpdates(int maxUpdates) {
    this->maxUpdates = maxUpdates;
}

