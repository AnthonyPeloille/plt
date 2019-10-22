
#include "GridTileSet.h"

render::GridTileSet::GridTileSet() {
    Tile *wall_left = new Tile(16, 0, 16, 16);
    this->walls.push_back(*wall_left);
    Tile *wall_mid = new Tile(32, 0, 16, 16);
    this->walls.push_back(*wall_mid);
    Tile *wall_right = new Tile(48, 0, 16, 16);
    this->walls.push_back(*wall_right);
}

const render::Tile &render::GridTileSet::getTile(const state::Element &e) {
    return TileSet::getTile(e);
}
