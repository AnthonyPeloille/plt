
#include "Surface.h"
#include "Tile.h"

render::Surface::Surface(int width, int height) :width(width), height(height){
    this->texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
}

void render::Surface::initQuads(int count) {
    quads.setPrimitiveType(sf::Quads);
    quads.resize(count);
}

void render::Surface::setSprite(const Tile &tex, int j, int i, sf::Color color) {
    sf::Vertex* quad = &quads[(i*this->height+j)*4];

    quad[0].position = sf::Vector2f((tex.getHeight()*i)*1.f,(tex.getWidth()*j)*1.f);
    quad[1].position = sf::Vector2f((tex.getHeight()*i)*1.f,(tex.getWidth()*(j+1))*1.f);
    quad[2].position = sf::Vector2f((tex.getHeight()*(i+1))*1.f,(tex.getWidth()*(j+1))*1.f);
    quad[3].position = sf::Vector2f((tex.getHeight()*(i+1))*1.f,(tex.getWidth()*j)*1.f);

    quad[0].texCoords = sf::Vector2f(tex.getX()*1.f,tex.getY()*1.f);
    quad[1].texCoords = sf::Vector2f(tex.getX()*1.f,(tex.getY()+tex.getWidth())*1.f);
    quad[2].texCoords = sf::Vector2f((tex.getX()+tex.getHeight())*1.f,(tex.getY()+tex.getWidth())*1.f);
    quad[3].texCoords = sf::Vector2f((tex.getX()+tex.getHeight())*1.f,tex.getY()*1.f);

    quad[0].color = color;
    quad[1].color = color;
    quad[2].color = color;
    quad[3].color = color;

}

void render::Surface::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    states.texture = &texture;

    target.draw(quads,states);

}

const sf::Texture &render::Surface::getTexture() const {
    return this->texture;
}

void render::Surface::setTexture(const sf::Texture &texture) {
    this->texture = texture;
}

