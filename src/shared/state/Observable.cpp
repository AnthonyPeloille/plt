

#include "Observable.h"
#include <algorithm>

void const state::Observable::registerObserver(Observer *o) {
    this->observer.push_back(o);
}

void const state::Observable::notifyObserver(const Event &e) {
    for (auto o : observer)
        o->stateChanged(e);
}

void const state::Observable::unregisterObserver(state::Observer *o) {
    observer.erase(find(observer.cbegin(),observer.cend(),o));
}

state::Observable::~Observable() = default;

