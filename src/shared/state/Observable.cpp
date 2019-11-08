

#include "Observable.h"
#include <algorithm>

void state::Observable::registerObserver(Observer *o) const{
    this->observer.push_back(o);
}

void state::Observable::notifyObserver(const Event &e) const{
    for (auto o : observer){
        o->stateChanged(e);
    }
}

void state::Observable::unregisterObserver(state::Observer *o) const{
    observer.erase(find(observer.cbegin(),observer.cend(),o));
}

state::Observable::~Observable() = default;

