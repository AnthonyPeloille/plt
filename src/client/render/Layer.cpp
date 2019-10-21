
#include "Layer.h"

render::Layer::Layer() {

}

render::Layer::~Layer() {

}

const render::Surface *const render::Layer::getSurface() {
    return this->surface.get();
}

void render::Layer::setSurface(Surface *surface) {
    this->surface = std::unique_ptr<Surface>(surface);
}

const std::shared_ptr <render::TileSet> &render::Layer::getTileset() const {
    return this->tileset;
}

void render::Layer::setTileset(const std::shared_ptr <render::TileSet> &tileset) {
    this->tileset = tileset;
}
