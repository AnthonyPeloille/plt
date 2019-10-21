
#include "Tile.h"

render::Tile::Tile() {
    this-> width = 0;
    this->height = 0;
}

render::Tile::Tile(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}

int render::Tile::getX() const {
    return x;
}

void render::Tile::setX(int x) {
    this->x = x;
}

int render::Tile::getY() const {
    return y;
}

void render::Tile::setY(int y) {
    this->y = y;
}

int render::Tile::getWidth() const {
    return width;
}

void render::Tile::setWidth(int width) {
    this->width = width;
}

int render::Tile::getHeight() const {
    return height;
}

void render::Tile::setHeight(int height) {
    this->height = height;
}
