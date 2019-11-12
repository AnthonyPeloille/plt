#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <state/State.h>
#include "StateLayer.h"
#include "CharsTileSet.h"

render::StateLayer::StateLayer(const state::State &state):state(state){
    this->surface = std::unique_ptr<Surface>(new Surface(0,0));
    this->tileset = std::make_shared<CharsTileSet>();
    this->font.loadFromFile("../res/Font/ThickThinPixel.ttf");
    this->state.registerObserver(this);
}

void render::StateLayer::initSurface() {
    //int type_id;
    std::stringstream id;

    sf::Text title;
    title.setFont(this->font);
    title.setString("TEST");
    title.setCharacterSize(16);
    title.setFillColor(sf::Color::White);

    //sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(0,0);
    title.setPosition(sf::Vector2f(160,16));

    sf::Sprite heart1;
    heart1.setTexture(this->surface->getTexture());
    heart1.setTextureRect(sf::IntRect(288, 256, 16, 16));
    heart1.setOrigin(0,0);
    heart1.setPosition(sf::Vector2f(16.f,16.f));

    this->menu_top.push_back(std::make_shared<sf::Text>(title));
    this->menu_top.push_back(std::make_shared<sf::Sprite>(heart1));

    sf::RectangleShape MoveBox(sf::Vector2f(140.f, 60.f));
    MoveBox.setFillColor(sf::Color(250,250,250));
    MoveBox.setPosition(sf::Vector2f(1132.f,96.f));

    sf::Text MoveText;
    MoveText.setFont(this->font);
    MoveText.setString("DEPLACEMENT");
    MoveText.setCharacterSize(16);
    MoveText.setFillColor(sf::Color::Black);
    MoveText.setPosition(sf::Vector2f(1136.f,104.f));

    sf::RectangleShape AttackBox(sf::Vector2f(140.f, 60.f));
    AttackBox.setFillColor(sf::Color(250,250,250));
    AttackBox.setPosition(sf::Vector2f(1132.f,192.f));

    sf::Text AttackText;
    AttackText.setFont(this->font);
    AttackText.setString("ATTAQUE");
    AttackText.setCharacterSize(16);
    AttackText.setFillColor(sf::Color::Black);
    AttackText.setPosition(sf::Vector2f(1136.f,200.f));

    this->menu_side.push_back(std::make_shared<sf::RectangleShape>(MoveBox));
    this->menu_side.push_back(std::make_shared<sf::Text>(MoveText));
    this->menu_side.push_back(std::make_shared<sf::RectangleShape>(AttackBox));
    this->menu_side.push_back(std::make_shared<sf::Text>(AttackText));

    for(auto chrs : this->state.getChars()){
        id.str("");
        id << chrs->getTypeId() << 1;
        Tile mc_tile = this->tileset->getTile(std::stoi(id.str()));
        sf::Sprite mc;
        mc.setTexture(this->surface->getTexture());
        mc.setTextureRect(sf::IntRect(mc_tile.getX(), mc_tile.getY(), mc_tile.getWidth(), mc_tile.getHeight()));
        mc.setOrigin(0,0);
        mc.setPosition(sf::Vector2f(16*chrs->getPosition().getX()-(mc_tile.getWidth()-16),16*chrs->getPosition().getY()-(mc_tile.getHeight()-8)));
        this->chars.push_back(std::make_shared<sf::Sprite>(mc));
    }

    for(auto mons : this->state.getMonsters()){
        id.str("");
        id << mons->getTypeId() << 1;
        //std::cout << std::stoi(id.str()) << std::endl;
        Tile mc_tile = this->tileset->getTile(std::stoi(id.str()));
        sf::Sprite mc;
        mc.setTexture(this->surface->getTexture());
        mc.setTextureRect(sf::IntRect(mc_tile.getX(), mc_tile.getY(), mc_tile.getWidth(), mc_tile.getHeight()));
        mc.setOrigin(0,0);
        mc.setPosition(sf::Vector2f(16*mons->getPosition().getX()-(mc_tile.getWidth()-16),16*mons->getPosition().getY()-(mc_tile.getHeight()-8)));
        this->monsters.push_back(std::make_shared<sf::Sprite>(mc));
    }

}

void render::StateLayer::stateChanged(const state::Event &e) {
    int type_id;
    std::stringstream id;

    sf::Text title;
    title.setFont(this->font);
    title.setString("TEST");
    title.setCharacterSize(16);
    title.setFillColor(sf::Color::White);

    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(0,0);
    title.setPosition(sf::Vector2f(160,16));

    sf::Sprite heart1;
    heart1.setTexture(this->surface->getTexture());
    heart1.setTextureRect(sf::IntRect(288, 256, 16, 16));
    heart1.setOrigin(0,0);
    heart1.setPosition(sf::Vector2f(16,16));

    this->menu_top.push_back(std::make_shared<sf::Text>(title));
    this->menu_top.push_back(std::make_shared<sf::Sprite>(heart1));
    int i = 0;
    for(auto chrs : this->state.getChars()){
        id.str("");
        id << chrs->getTypeId() << 1;
        Tile mc_tile = this->tileset->getTile(std::stoi(id.str()));
        dynamic_cast<sf::Sprite*>(this->chars[i].get())->setPosition(sf::Vector2f(16*chrs->getPosition().getX()-(mc_tile.getWidth()-16),16*chrs->getPosition().getY()-(mc_tile.getHeight()-8)));
        i++;
    }

    i = 0;
    for(auto mons : this->state.getMonsters()){
        id.str("");
        id << mons->getTypeId() << 1;
        Tile mc_tile = this->tileset->getTile(std::stoi(id.str()));
        dynamic_cast<sf::Sprite*>(this->monsters[i].get())->setPosition(sf::Vector2f(16*mons->getPosition().getX()-(mc_tile.getWidth()-16),16*mons->getPosition().getY()-(mc_tile.getHeight()-8)));
        i++;
    }

}

const sf::Font &render::StateLayer::getFont() const {
    return this->font;
}

void render::StateLayer::setFont(const sf::Font &font) {

}

const std::vector<std::shared_ptr<sf::Drawable>> &render::StateLayer::getMenu_top() const {
    return this->menu_top;
}

void render::StateLayer::setMenu_top(const std::vector<std::shared_ptr<sf::Drawable>> &menu_top) {
    this->menu_top = menu_top;
}

const std::vector<std::shared_ptr<sf::Drawable>> &render::StateLayer::getChars() const {
    return this->chars;
}

void render::StateLayer::setChars(const std::vector<std::shared_ptr<sf::Drawable>> &chars) {
    this->chars = chars;
}

const std::vector<std::shared_ptr<sf::Drawable>> &render::StateLayer::getMenu_side() const {
    return menu_side;
}

void render::StateLayer::setMenu_side(const std::vector<std::shared_ptr<sf::Drawable>> &menu_side) {
    this->menu_side = menu_side;
}

const std::vector<std::shared_ptr<sf::Drawable>> &render::StateLayer::getMonsters() const {
    return this->monsters;
}

void render::StateLayer::setMonsters(const std::vector<std::shared_ptr<sf::Drawable>> &monsters) {
    this->monsters = monsters;
}
