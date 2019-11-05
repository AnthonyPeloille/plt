#include "Scene.h"

render::Scene::Scene(const state::State &state) :state(state),stateLayer(this->state),floorLayer(this->state.getFloor(),1), wallLayer(this->state.getWall(),1), charsLayer(this->state.getChars(),1) {

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
    this->floorLayer.initSurface();
    this->wallLayer.initSurface();
    this->charsLayer.initSurface();
    window.draw(*this->floorLayer.getSurface());
    window.draw(*this->wallLayer.getSurface());
    window.draw(*this->charsLayer.getSurface());
}
