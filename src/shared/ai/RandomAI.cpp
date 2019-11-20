

#include <engine/AttackCommand.h>
#include <engine/Engine.h>
#include <engine/MoveCommand.h>
#include "RandomAI.h"

ai::RandomAI::RandomAI(int randomSeed) {
    this->randgen.seed(randomSeed);
}

void ai::RandomAI::run(engine::Engine &engine, state::MainCharacter &character) {
    std::uniform_int_distribution<int> commandes(0,1);
    std::uniform_int_distribution<int> directions(0,3);
    int commande = commandes(this->randgen);
    if(commande == 0){
        int direction = directions(this->randgen);
        auto* pos = new state::Coords(character.getPosition());
        if(direction == 0){
            auto* move = new engine::MoveCommand(
                    &character, new state::Coords(pos->getX()+1,pos->getY()));
            engine.addCommand(1, move);
        }else if(direction == 1){
            auto* move = new engine::MoveCommand(
                    &character, new state::Coords(pos->getX()-1,pos->getY()));
            engine.addCommand(1, move);
        }else if(direction == 2){
            auto* move = new engine::MoveCommand(
                    &character, new state::Coords(pos->getX(),pos->getY()+1));
            engine.addCommand(1, move);
        }else{
            auto* move = new engine::MoveCommand(
                    &character, new state::Coords(pos->getX(),pos->getY()-1));
            engine.addCommand(1, move);
        }
    }else{
        auto* attack = new engine::AttackCommand(&character);
        engine.addCommand(0,attack);
    }
}

