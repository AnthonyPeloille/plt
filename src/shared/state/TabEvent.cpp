

#include "TabEvent.h"

state::TabEvent::TabEvent(int x, int y) {
    this->x = x;
    this->y = y;
}

const state::EventTypeId state::TabEvent::getEventType() {
    return EVENT_TAB;
}

