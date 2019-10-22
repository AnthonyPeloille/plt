
#include "ElementTabLayer.h"

render::ElementTabLayer::ElementTabLayer(const state::ElementTab &tab):tab(tab) {

}

void render::ElementTabLayer::initSurface() {
    this->surface = std::unique_ptr<Surface>(new Surface());
    this->surface->initQuads(this->tab.getHeight()*this->tab.getWidth()*4);
    for(int i = 0; i < this->tab.getHeight(); i++){
        for(int j = 0; j < this->tab.getWidth(); j++) {
            auto *tile = new render::Tile(16*i, 16*j, 16, 16);
            this->surface->setSprite(*tile,i,j);
        }
    }
}

void render::ElementTabLayer::stateChanged(const state::Event &e) {

}
