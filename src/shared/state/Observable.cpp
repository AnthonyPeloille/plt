

#include "Observable.h"

void state::Observable::registerObserver(Observer *observer) {
    this->observer.push_back(observer);
}

void state::Observable::notifyObserver(const StateEvent &e) {
    for (auto o : observer)
        o->stateChanged(e);
}

state::Observable::~Observable() = default;

