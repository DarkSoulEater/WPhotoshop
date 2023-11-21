#ifndef ___MOUSEPRESSEDEVENT_H___
#define ___MOUSEPRESSEDEVENT_H___

#include "Core/Event/Event.h"
#include "Core/Event/MouseButton.h"
#include "Math/Vector2.h"


struct MousePressedEvent : public Event {
    MousePressedEvent(MouseButton ButtonID, Vec2d position) : Event(EventType::MousePressed), button_id(ButtonID), pos(position) {}

    MouseButton button_id;
    bool shift, ctrl, alt;
    Vec2d pos = Vec2d(0, 0);
};

#endif // ___MOUSEPRESSEDEVENT_H___