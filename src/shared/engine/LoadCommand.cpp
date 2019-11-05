
#include "LoadCommand.h"

engine::LoadCommand::LoadCommand(const char *f) :file_name(f){

}

engine::CommandTypeId engine::LoadCommand::getTypeId() const {
    return LOAD;
}

void engine::LoadCommand::execute(state::State &state) {

}
