#ifndef ___MOUSERELEASEDEVENT_H___
#define ___MOUSERELEASEDEVENT_H___

#include "Core/Event/Event.h"
#include "Core/Event/MouseButton.h"
#include "Math/Vector2.h"

struct MouseReleasedEvent : public Event {
    MouseReleasedEvent(MouseButton ButtonID, Vec2d position) : Event(EventType::MouseReleased), button_id(ButtonID), pos(position) {}

    MouseButton button_id;
    bool shift, ctrl, alt;
    Vec2d pos = Vec2d(0, 0);
};

#endif // ___MOUSERELEASEDEVENT_H___