
#include "Surface.h"
#include "Tile.h"

render::Surface::Surface() {
    this->texture.loadFromFile("../res/DungeonTiles/0x72_DungeonTilesetII_v1.3.png");
}

void render::Surface::initQuads(int count) {
    quads.setPrimitiveType(sf::Quads);
    quads.resize(count);
}

void render::Surface::setSprite(const Tile &tex) {
    sf::Vertex quad[4];

    //quad[0].position = sf::Vector2f(16,16);
   // quad[1].position = sf::Vector2f(16,16+tex.getY());
   // quad[2].position = sf::Vector2f(16+tex.getX(),16+tex.getY());
//    quad[3].position = sf::Vector2f(16+tex.getX(),16);
//
//    quad[0].color = sf::Color::Red;
//    quad[1].color = sf::Color::Blue;
//    quad[2].color = sf::Color::Green;
//    quad[2].color = sf::Color::Yellow;
//
//    //quad[0].texCoords = sf::Vector2f(16,16);
//    //quad[1].texCoords = sf::Vector2f(16,16+tex.getY());
//    //quad[2].texCoords = sf::Vector2f(16+tex.getX(),16+tex.getY());
//    //quad[3].texCoords = sf::Vector2f(16+tex.getX(),16);
//
//    this->quads.append(*quad);
    sf::Vertex triangle[4];

// on définit la position des sommets du triangle
    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(100.f, 100.f);
    triangle[3].position = sf::Vector2f(10.f, 100.f);
// on définit la couleur des sommets du triangle
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;
    triangle[3].color = sf::Color::Yellow;
    this->quads[0] = *triangle;
}

void render::Surface::draw(sf::RenderTarget &target, sf::RenderStates states) const{

    //states.texture = &texture;
    //target.draw(quads, states);

    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    //sprite.setTextureRect(sf::IntRect(16, 16, 16, 16));
    //sprite.setPosition(100, 25);

    target.draw(quads);

}
