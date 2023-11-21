#ifndef ___KEYBOARDRELEASEDEVENT_H___
#define ___KEYBOARDRELEASEDEVENT_H___

#include "Core/Event/Event.h"
#include "Core/Event/KeyCode.h"
#include "Math/Vector2.h"

struct KeyboardReleasedEvent : public Event {
    KeyboardReleasedEvent(KeyCode key, Vec2d position) : Event(EventType::KeyboardReleased), key_id(key), pos(position) {}

    KeyCode key_id;
    bool shift, ctrl, alt;
    Vec2d pos = Vec2d(0, 0);
};

#endif // ___KEYBOARDRELEASEDEVENT_H___