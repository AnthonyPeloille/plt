

#include "State.h"

state::ElementTab &state::State::getGrid() {
    return grid;
}

state::ElementTab &state::State::getChars() {
    return chars;
}

int state::State::getEpoch() const {
    return epoch;
}

void state::State::setEpoch(int epoch) {
    this->epoch = epoch;
}

int state::State::getEpochRate() const {
    return epochRate;
}

void state::State::setEpochRate(int epochRate) {
    this->epochRate = epochRate;
}

