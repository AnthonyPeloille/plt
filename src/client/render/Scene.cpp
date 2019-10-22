#include "Scene.h"

render::Scene::Scene(const state::State &state) :state(state),stateLayer(this->state),gridLayer(this->state.getGrid()), charsLayer(this->state.getChars()) {

}

const size_t render::Scene::getWidth() {
    return 400;
}

const size_t render::Scene::getHeight() {
    return 400;
}

void render::Scene::stateChanged(const state::Event &event) {

}

void render::Scene::draw(sf::RenderWindow &window) {
    this->gridLayer.initSurface();
    window.draw(*this->gridLayer.getSurface());
}
