
#include "ElementTabLayer.h"

render::ElementTabLayer::ElementTabLayer(const state::ElementTab &tab):tab(tab) {

}

void render::ElementTabLayer::initSurface() {
    this->surface = std::unique_ptr<Surface>(new Surface());
    this->surface->initQuads(4);
    auto* tile = new render::Tile(16, 16, 16, 16);
    this->surface->setSprite(*tile);
}

void render::ElementTabLayer::stateChanged(const state::Event &e) {

}
