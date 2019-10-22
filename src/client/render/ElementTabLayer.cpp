
#include "ElementTabLayer.h"

render::ElementTabLayer::ElementTabLayer(const state::ElementTab &tab):tab(tab) {

}

void render::ElementTabLayer::initSurface() {
    this->surface = std::unique_ptr<Surface>(new Surface());
    this->surface.get()->initQuads(4);
}
