#include "StateTileSet.h"

render::StateTileSet::StateTileSet() {
    Tile *knight = new Tile(128, 112, 16, 16);
    this->tiles.push_back(*knight);
    Tile *necromancer = new Tile(368, 268, 16, 20);
    this->tiles.push_back(*necromancer);
    Tile *demon = new Tile(16, 364, 32, 36);
    this->tiles.push_back(*demon);
}

const render::Tile &render::StateTileSet::getTile(int e) {
    if (e == 31)
        return this->tiles.at(0);
    if (e == 41)
        return this->tiles.at(0);
}

