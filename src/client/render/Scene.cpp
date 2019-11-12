#include "Scene.h"

render::Scene::Scene(const state::State &state, sf::RenderWindow& window) :state(state),stateLayer(this->state),floorLayer(this->state.getFloor(),1), wallLayer(this->state.getWall(),1), window(window){
    this->state.registerObserver(this);
    this->floorLayer.initSurface();
    this->wallLayer.initSurface();
    this->stateLayer.initSurface();
}

const size_t render::Scene::getWidth() {
    return 400;
}

const size_t render::Scene::getHeight() {
    return 400;
}

void render::Scene::stateChanged(const state::Event &event) {
    this->draw();
}

void render::Scene::draw() {
    this->window.draw(*this->floorLayer.getSurface());
    this->window.draw(*this->wallLayer.getSurface());
    for(auto drawable : this->stateLayer.getMenu_top()){
        this->window.draw(*drawable);
    }
    for(auto drawable : this->stateLayer.getMenu_side()){
        this->window.draw(*drawable);
    }
    for(auto drawable : this->stateLayer.getChars()){
        this->window.draw(*drawable);
    }
    this->window.display();
}
