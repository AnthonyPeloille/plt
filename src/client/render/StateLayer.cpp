
#include <state/State.h>
#include "StateLayer.h"

render::StateLayer::StateLayer(const state::State &state):state(state){
    this->surface = std::unique_ptr<Surface>();
}

void render::StateLayer::initSurface() {

}

void render::StateLayer::stateChanged(const state::Event &e) {

}
