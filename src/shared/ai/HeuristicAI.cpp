
#include "HeuristicAI.h"

ai::HeuristicAI::HeuristicAI(const state::State &state, int randomSeed) :AI(state){
    this->randgen.seed(randomSeed);
}

const ai::PathMap &ai::HeuristicAI::getMonstersMap() const {
    return this->monstersMap;
}

void ai::HeuristicAI::stateChanged(const state::Event &event) {

}

void ai::HeuristicAI::run(engine::Engine &engine) {

}
