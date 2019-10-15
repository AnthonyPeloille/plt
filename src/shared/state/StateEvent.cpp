

#include "StateEvent.h"

state::StateEvent::StateEvent(StateEventId se) {
    this->stateEvent = se;
}

const state::EventTypeId state::StateEvent::getEventType() {
    return EVENT_STATE;
}

void stateChanged(const state::Event& event){

}

