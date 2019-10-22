
#include "ElementTabLayer.h"

render::ElementTabLayer::ElementTabLayer(const state::ElementTab &tab):tab(tab) {

}

void render::ElementTabLayer::initSurface() {
    this->surface = std::unique_ptr<Surface>(new Surface(this->tab.getWidth(),this->tab.getHeight()));
    this->surface->initQuads(this->tab.getHeight()*this->tab.getWidth()*4);
    for(size_t i = 0; i < this->tab.getHeight(); i++){
        for(size_t j = 0; j < this->tab.getWidth(); j++) {
            auto *tile = new render::Tile(16, 16, 16, 16);
            this->surface->setSprite(*tile,i,j);
        }
    }
}

void render::ElementTabLayer::stateChanged(const state::Event &e) {

}
