#include <memory>
#include <state/State.h>
#include "StateLayer.h"
#include "CharsTileSet.h"

render::StateLayer::StateLayer(const state::State &state):state(state){
    this->surface = std::unique_ptr<Surface>();
    this->tileset = std::make_shared<CharsTileSet>();
    this->font.loadFromFile("../res/Font/ThickThinPixel.ttf");
}

void render::StateLayer::initSurface() {
    sf::Text title;
    title.setFont(this->font);
    title.setString("TEST");
    title.setCharacterSize(16);
    title.setFillColor(sf::Color::White);

    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(0,0);
    title.setPosition(sf::Vector2f(16,16));

    this->menu.push_back(std::make_shared<sf::Text>(title));
}

void render::StateLayer::stateChanged(const state::Event &e) {

}

const sf::Font &render::StateLayer::getFont() const {
    return this->font;
}

void render::StateLayer::setFont(const sf::Font &font) {

}

const std::vector<std::shared_ptr<sf::Drawable>> &render::StateLayer::getMenu() const {
    return this->menu;
}

void render::StateLayer::setMenu(const std::vector<std::shared_ptr<sf::Drawable>> &menu) {

}
