
#include "Observable.h"
#include <algorithm>

engine::Observable::~Observable() = default;

void engine::Observable::registerObserver(Observer *o) const {
    this->observers.push_back(o);
}

void engine::Observable::notifyUpdating() const {
    for(auto observer : observers){
        observer->engineUpdating();
    }
}

void engine::Observable::notifyUpdated() const {
    for(auto observer : observers){
        observer->engineUpdated();
    }
}
