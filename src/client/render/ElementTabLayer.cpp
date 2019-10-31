
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <state/Wall.h>
#include <state/Space.h>
#include <state/Door.h>
#include <state/Chest.h>
#include <state/MainCharacter.h>
#include "ElementTabLayer.h"
#include "GridTileSet.h"

render::ElementTabLayer::ElementTabLayer(const state::ElementTab &tab):tab(tab) {
    this->tileset = std::make_shared<GridTileSet>();
}

void render::ElementTabLayer::initSurface() {
    this->surface = std::unique_ptr<Surface>(new Surface(this->tab.getWidth(),this->tab.getHeight()));
    this->surface->initQuads(this->tab.getHeight()*this->tab.getWidth()*4);
    Tile empty {0,0,16,16};
    for(size_t i = 0; i < this->tab.getHeight(); i++){
        for(size_t j = 0; j < this->tab.getWidth(); j++) {
            //auto *tile = new render::Tile(16, 16, 16, 16);
            std::stringstream tileId;
            state::TypeId tid;
            if(this->tab.get(i,j) != NULL) {
                tid = this->tab.get(i, j)->getTypeId();
                if (tid == state::WALL) {
                    state::Wall *e = dynamic_cast<state::Wall *>(this->tab.get(i, j));
                    tileId << tid << e->getWallTypeId();
                    this->surface->setSprite(this->tileset->getTile(std::stoi(tileId.str())), i, j);
                } else if (tid == state::SPACE) {
                    state::Space *e = dynamic_cast<state::Space *>(this->tab.get(i, j));
                    tileId << tid << e->getSpaceTypeId();
                    this->surface->setSprite(this->tileset->getTile(std::stoi(tileId.str())), i, j);
                } else if (tid == state::DOOR) {
                    state::Door *e = dynamic_cast<state::Door *>(this->tab.get(i, j));
                    tileId << tid << 0;
                    this->surface->setSprite(this->tileset->getTile(std::stoi(tileId.str())), i, j);
                } else if (tid == state::CHEST) {
                    state::Chest *e = dynamic_cast<state::Chest *>(this->tab.get(i, j));
                    tileId << tid << e->getChestContentId();
                    this->surface->setSprite(this->tileset->getTile(std::stoi(tileId.str())), i, j);
                }else if (tid == state::MC) {
                    state::MainCharacter *e = dynamic_cast<state::MainCharacter *>(this->tab.get(i, j));
                    tileId << tid;
                    this->surface->setSprite(this->tileset->getTile(std::stoi(tileId.str())), i, j);
                } else {
                    this->surface->setSprite(empty,i,j);
                }
            }else{

            }
        }
    }
}

void render::ElementTabLayer::stateChanged(const state::Event &e) {

}
