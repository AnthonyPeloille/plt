
#include "Surface.h"
#include "Tile.h"

render::Surface::Surface(int width, int height) :width(width), height(height){
    this->texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
}

void render::Surface::initQuads(int count) {
    quads.setPrimitiveType(sf::Quads);
    quads.resize(count);
}

void render::Surface::setSprite(const Tile &tex, int i, int j) {
    sf::Vertex* quad = &quads[(i*this->height+j)*4];

    quad[0].position = sf::Vector2f(tex.getHeight()*i,tex.getWidth()*j);
    quad[1].position = sf::Vector2f(tex.getHeight()*i,tex.getWidth()*j+tex.getY());
    quad[2].position = sf::Vector2f(tex.getHeight()*i+tex.getX(),tex.getWidth()*j+tex.getY());
    quad[3].position = sf::Vector2f(tex.getHeight()*i+tex.getX(),tex.getWidth()*j);

    quad[0].texCoords = sf::Vector2f(tex.getX(),tex.getY());
    quad[1].texCoords = sf::Vector2f(tex.getX(),tex.getY()+tex.getWidth());
    quad[2].texCoords = sf::Vector2f(tex.getX()+tex.getHeight(),tex.getY()+tex.getWidth());
    quad[3].texCoords = sf::Vector2f(tex.getX()+tex.getHeight(),tex.getY());

}

void render::Surface::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    states.texture = &texture;

    target.draw(quads,states);

}
