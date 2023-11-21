#ifndef ___KEYBOARDPRESSEDEVENT_H___
#define ___KEYBOARDPRESSEDEVENT_H___

#include "Core/Event/Event.h"
#include "Core/Event/KeyCode.h"
#include "Math/Vector2.h"

struct KeyboardPressedEvent : public Event {
    KeyboardPressedEvent(KeyCode key, Vec2d position) : Event(EventType::KeyboardPressed), key_id(key), pos(position) {}

    KeyCode key_id;
    bool shift, ctrl, alt;
    Vec2d pos = Vec2d(0, 0);
};

#endif // ___KEYBOARDPRESSEDEVENT_H___