#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <state/State.h>
#include <state/MainCharacter.h>
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

    sf::Text stat;
    stat.setFont(this->font);
    std::string str = "ATTAQUE : " + std::to_string(dynamic_cast<state::MainCharacter*>(this->state.getChars()[0].get())->getAttack()) + "   DEFENSE : " + std::to_string(dynamic_cast<state::MainCharacter*>(this->state.getChars()[0].get())->getDefense());
    stat.setString(str);
    stat.setCharacterSize(16);
    stat.setFillColor(sf::Color::White);

    //sf::FloatRect textRect = title.getLocalBounds();
    stat.setOrigin(0,0);
    stat.setPosition(sf::Vector2f(120,16));

    sf::Sprite heart1;
    heart1.setTexture(this->surface->getTexture());
    auto mc = dynamic_cast<state::MainCharacter*>(this->state.getChars()[0].get());
    if (mc->getHealthPoints() == 1){
        heart1.setTextureRect(sf::IntRect(304, 256, 16, 16));
    }else if(mc->getHealthPoints() == 0){
        heart1.setTextureRect(sf::IntRect(320, 256, 16, 16));
    }else {
        heart1.setTextureRect(sf::IntRect(288, 256, 16, 16));
    }
    heart1.setOrigin(0,0);
    heart1.setPosition(sf::Vector2f(16.f,18.f));

    sf::Sprite heart2 = heart1;
    if (mc->getHealthPoints() == 3){
        heart2.setTextureRect(sf::IntRect(304, 256, 16, 16));
    }else if(mc->getHealthPoints() == 2){
        heart2.setTextureRect(sf::IntRect(320, 256, 16, 16));
    }else {
        heart2.setTextureRect(sf::IntRect(288, 256, 16, 16));
    }
    heart2.setPosition(sf::Vector2f(36.f,18.f));

    sf::Sprite heart3 = heart1;
    if (mc->getHealthPoints() == 5){
        heart3.setTextureRect(sf::IntRect(304, 256, 16, 16));
    }else if(mc->getHealthPoints() == 4){
        heart3.setTextureRect(sf::IntRect(320, 256, 16, 16));
    }else {
        heart3.setTextureRect(sf::IntRect(288, 256, 16, 16));
    }
    heart3.setPosition(sf::Vector2f(56.f,18.f));

    this->menu_top.push_back(std::make_shared<sf::Text>(stat));
    this->menu_top.push_back(std::make_shared<sf::Sprite>(heart1));
    this->menu_top.push_back(std::make_shared<sf::Sprite>(heart2));
    this->menu_top.push_back(std::make_shared<sf::Sprite>(heart3));

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
    this->monsters.clear();
    this->chars.clear();
    this->menu_side.clear();
    this->menu_top.clear();
    initSurface();
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
