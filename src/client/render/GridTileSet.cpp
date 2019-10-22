
#include "GridTileSet.h"

render::GridTileSet::GridTileSet() {

    Tile *wall_corner_top_left = new Tile(32, 112, 16, 16);
    this->walls.push_back(*wall_corner_top_left);
    Tile *wall_corner_top_right = new Tile(48, 112, 16, 16);
    this->walls.push_back(*wall_corner_top_right);
    Tile *wall_corner_bottom_right = new Tile(48, 144, 16, 16);
    this->walls.push_back(*wall_corner_bottom_right);
    Tile *wall_corner_bottom_left = new Tile(32, 144, 16, 16);
    this->walls.push_back(*wall_corner_bottom_left);
    Tile *wall_mid = new Tile(16, 0, 16, 16);
    this->walls.push_back(*wall_mid);
    Tile *wall_side = new Tile(0, 128, 16, 16);
    this->walls.push_back(*wall_side);
    Tile *floor = new Tile(16,64,16,16);
    this->spaces.push_back(*floor);
    Tile *chest_closed = new Tile(304,288,16,16);
    this->chests.push_back(*chest_closed);

}

const render::Tile &render::GridTileSet::getTile(int id) {
    if (id==11)
        return this->walls.at(0);
    if (id==12)
        return this->walls.at(1);
    if (id==13)
        return this->walls.at(2);
    if (id==14)
        return this->walls.at(3);
    if (id==15)
        return this->walls.at(4);
    if (id==16)
        return this->walls.at(5);
    if (id==21)
        return this->spaces.at(0);
    if (id==41)
        return this->chests.at(0);
}
