

#include "StateEvent.h"

state::StateEvent::StateEvent(StateEventId stateEvent) {
    this->stateEventId = stateEvent;
}

const state::EventTypeId state::StateEvent::getEventType() {
    return EVENT_STATE;
}

