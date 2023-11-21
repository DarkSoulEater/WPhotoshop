#ifndef ___MOUSEMOVEEVENT_H___
#define ___MOUSEMOVEEVENT_H___

#include "Core/Event/Event.h"
#include "Math/Vector2.h"

struct MouseMoveEvent : public Event {
    MouseMoveEvent(Vec2d position) : Event(EventType::MouseMove), pos(position) {}

    bool shift, ctrl, alt;
    Vec2d pos = Vec2d(0, 0);
};

#endif // ___MOUSEMOVEEVENT_H___