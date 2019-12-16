
#include "Observable.h"
#include <algorithm>

engine::Observable::~Observable() = default;

void engine::Observable::registerObserver(Observer *o) const {
    this->observers.push_back(o);
}

void engine::Observable::notifyUpdating() const {

}

void engine::Observable::notifyUpdated() const {

}
