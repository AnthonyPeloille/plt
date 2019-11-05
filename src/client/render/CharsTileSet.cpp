

#include "CharsTileSet.h"

render::CharsTileSet::CharsTileSet() {
    Tile *knight = new Tile(128, 112, 16, 16);
    this->main_character.push_back(*knight);
    Tile *necromancer = new Tile(368, 268, 16, 20);
    this->ghost.push_back(*necromancer);
    Tile *demon = new Tile(16, 364, 32, 36);
    this->boss.push_back(*demon);
}

const render::Tile &render::CharsTileSet::getTile(int e) {
    if (e == 31)
        return this->main_character.at(0);
    if (e == 41)
        return this->ghost.at(0);
}

