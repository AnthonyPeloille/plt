

#include "AI.h"
#include "engine/MoveCommand.h"
#include "engine/AttackCommand.h"


void ai::AI::listCommands(std::vector<std::unique_ptr<engine::Command>> &list, const state::State &state,
                          state::MainCharacter &character) {
    //list.push_back(engine::MoveCommand(character, character.getPosition()));
    //list.push_back(engine::AttackCommand(character));
}
