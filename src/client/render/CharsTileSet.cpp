

#include "CharsTileSet.h"

render::CharsTileSet::CharsTileSet() {
    Tile *knight = new Tile(128, 100, 16, 28);
    this->main_character.push_back(*knight);
    Tile *necromancer = new Tile(368, 268, 16, 20);
    this->ghost.push_back(*necromancer);
    Tile *demon = new Tile(16, 364, 32, 36);
    this->boss.push_back(*demon);
}

const render::Tile &render::CharsTileSet::getTile(int e) {
    return TileSet::getTile(e);
}

