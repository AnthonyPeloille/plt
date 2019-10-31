
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
    Tile *wall_side_right = new Tile(0, 128, 16, 16);
    this->walls.push_back(*wall_side_right);
    Tile *wall_side_left = new Tile(16, 128, 16, 16);
    this->walls.push_back(*wall_side_left);
    Tile *wall_top = new Tile(16, 16, 16, 16);
    this->walls.push_back(*wall_top);
    Tile *wall_corner_left = new Tile(32, 128, 16, 16);
    this->walls.push_back(*wall_corner_left);
    Tile *wall_corner_right = new Tile(48, 128, 16, 16);
    this->walls.push_back(*wall_corner_right);
    Tile *wall_corner_front_left = new Tile(32, 160, 16, 16);
    this->walls.push_back(*wall_corner_front_left);
    Tile *wall_corner_front_right = new Tile(48, 160, 16, 16);
    this->walls.push_back(*wall_corner_front_right);
    Tile *wall_inner_corner_l_top_left = new Tile(80, 128, 16, 16);
    this->walls.push_back(*wall_inner_corner_l_top_left);
    Tile *wall_inner_corner_l_top_right = new Tile(64, 128, 16, 16);
    this->walls.push_back(*wall_inner_corner_l_top_right);
    Tile *wall_inner_corner_mid_left = new Tile(80, 144, 16, 16);
    this->walls.push_back(*wall_inner_corner_mid_left);
    Tile *wall_inner_corner_mid_right = new Tile(64, 144, 16, 16);
    this->walls.push_back(*wall_inner_corner_mid_right);
    Tile *wall_inner_corner_t_top_left = new Tile(80, 160, 16, 16);
    this->walls.push_back(*wall_inner_corner_t_top_left);
    Tile *wall_inner_corner_t_top_right = new Tile(64, 160, 16, 16);
    this->walls.push_back(*wall_inner_corner_t_top_right);
    Tile *floor_clean = new Tile(16,64,16,16);
    this->spaces.push_back(*floor_clean);
    Tile *floor_cracked = new Tile(32,64,16,16);
    this->spaces.push_back(*floor_cracked);
    Tile *floor_hole_right = new Tile(48,64,16,16);
    this->spaces.push_back(*floor_hole_right);
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
    if (id==17)
        return this->walls.at(6);
    if (id==18)
        return this->walls.at(7);
    if (id==19)
        return this->walls.at(8);
    if (id==110)
        return this->walls.at(9);
    if (id==111)
        return this->walls.at(10);
    if (id==112)
        return this->walls.at(11);
    if (id==113)
        return this->walls.at(12);
    if (id==114)
        return this->walls.at(13);
    if (id==115)
        return this->walls.at(14);
    if (id==116)
        return this->walls.at(15);
    if (id==117)
        return this->walls.at(16);
    if (id==118)
        return this->walls.at(17);
    if (id==21)
        return this->spaces.at(0);
    if (id==22)
        return this->spaces.at(1);
    if (id==23)
        return this->spaces.at(2);
    if (id==62)
        return this->chests.at(0);
}
