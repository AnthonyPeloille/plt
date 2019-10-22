

#include "TileSet.h"

render::TileSet::~TileSet() {

}

const render::Tile &render::TileSet::getCharTile(char c) {
    return Tile();
}

int const render::TileSet::getCellWidth(Tile tile) {
    return tile.getWidth();
}

int const render::TileSet::getCellHeight(Tile tile) {
    return tile.getHeight();
}

