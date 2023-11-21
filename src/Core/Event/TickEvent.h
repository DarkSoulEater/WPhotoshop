#ifndef ___TICKEVENT_H___
#define ___TICKEVENT_H___

#include "Core/Event/Event.h"

struct TickEvent : public Event {
    TickEvent() : Event(EventType::Tick) {}
    double delta_time = 0;
};

#endif // ___TICKEVENT_H___