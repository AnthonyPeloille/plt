

#include <engine/AttackCommand.h>
#include <engine/Engine.h>
#include <engine/MoveCommand.h>
#include <engine/PatternMonsterCommand.h>
#include "AdvancedAI.h"
#include "HeuristicAI.h"

ai::AdvancedAI::AdvancedAI(const state::State &state, int randomSeed) : AI(state) {
    this->randgen.seed(randomSeed);
    this->monstersMap.init(state.getWall(),state.getMonsters(),*dynamic_cast<state::MainCharacter*>(state.getChars()[0].get()), state.getExit());
}

const ai::PathMap &ai::AdvancedAI::getMonstersMap() const {
    return this->monstersMap;
}

void ai::AdvancedAI::stateChanged(const state::Event &event) {

}

void ai::AdvancedAI::run(engine::Engine &engine, state::MainCharacter &character) {
    int depth = 100;
    int updateCount = 0;
    if((depth < this->maxDepth) & (updateCount < this->maxUpdates)){
        minmax(engine,depth,true);
        updateCount++;
    }else{
        this->monstersMap.init(engine.getState().getWall(),engine.getState().getMonsters(),character,engine.getState().getExit());
        std::uniform_int_distribution<int> commandes(0,1);
        std::uniform_int_distribution<int> directions(0,3);
        auto queue = this->monstersMap.getQueue();
        int commande = commandes(this->randgen);
        if(engine.getState().getMonsters().size() > 0){
            auto *pattern = new engine::PatternMonsterCommand(
                    *dynamic_cast<state::Monster *>(engine.getState().getMonsters()[0].get()));
            engine.addCommand(2, pattern);
        }
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

int ai::AdvancedAI::minmax(engine::Engine &engine, int depth, bool isMaximizing) {
    if (isMaximizing){
        int bestScore = -INFINITY;
        for(size_t i = 0; i < engine.getState().getWall().getHeight(); i++){
            for(size_t j = 0; j < engine.getState().getWall().getWidth(); j++) {
                if (engine.getState().getWall().get(i,j) == nullptr) {
                    int score = minmax(engine, depth + 1, false);
                    if (score  > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }else{
        int bestScore = INFINITY;
        for(size_t i = 0; i < engine.getState().getWall().getHeight(); i++){
            for(size_t j = 0; j < engine.getState().getWall().getWidth(); j++) {
                if (engine.getState().getWall().get(i,j) == nullptr) {
                    int score = minmax(engine, depth + 1, false);
                    if (score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
    return 0;
}

