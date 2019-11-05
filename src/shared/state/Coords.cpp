
#include "Coords.h"

state::Coords::Coords() {
    this->x = 0;
    this->y = 0;
}

state::Coords::Coords(int x, int y) {
    this->x = x;
    this->y = y;
}

bool state::Coords::operator==(const Coords &a) {
    return this->x == a.getX() && this->y == a.getY();
}

int state::Coords::getX() const {
    return x;
}

void state::Coords::setX(int x) {
    this->x = x;
}

int state::Coords::getY() const {
    return y;
}

void state::Coords::setY(int y) {
    this->y = y;
}
