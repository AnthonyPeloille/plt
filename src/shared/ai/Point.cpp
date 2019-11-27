
#include "Point.h"

ai::Point::Point(state::Coords Coord, int w) {
    this->coord = Coord;
    this->weight = w;
}

const state::Coords &ai::Point::getCoord() const {
    return this->coord;
}

void ai::Point::setCoord(const state::Coords &coord) {
    this->coord = coord;
}

int ai::Point::getWeight() const {
    return this->weight;
}

void ai::Point::setWeight(int weight) {
    this->weight = weight;
}
