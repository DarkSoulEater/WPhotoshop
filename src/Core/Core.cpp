#include "Core.h"

Core::Core() : main_window_(sf::VideoMode(1, 1), "", sf::Style::Fullscreen) {}

void Core::Run() {
    while (main_window_.isOpen()) {
        PollEvent();
        Tick();

        Clear();
        Draw();
        Display();
    }
}

void Core::Stop() {
    main_window_.close();
}

void Core::AddSeeker(Widget &widget) {
    widgets_.push_back(&widget);
}

void Core::Clear() {
    main_window_.clear(sf::Color::Black);
}

void Core::Display() {
    main_window_.display();
}

void Core::Draw() {
    WTransformStack tr_stack;
    for (Widget* widget : widgets_) {
        widget->draw(tr_stack, rt_window_);
    }
}

void Core::Tick() {
    // TODO:
}

#define SetControlButton(EVENT)           \
    EVENT.shift = sfml_event.key.shift;   \
    EVENT.ctrl  = sfml_event.key.control; \
    EVENT.alt   = sfml_event.key.alt;     \

void Core::PollEvent() {
    sf::Vector2i imouse_pos = sf::Mouse::getPosition(main_window_);
    Vec2d mouse_pos = Vec2d(imouse_pos.x, imouse_pos.y);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-enum"

    sf::Event sfml_event;
    while (main_window_.pollEvent(sfml_event)) {
    switch (sfml_event.type) {
        // Close
        case sf::Event::Closed: {
            Stop();
        } break;

        // Mouse
        case sf::Event::MouseMoved: {
            MouseMoveEvent event(mouse_pos);
            SetControlButton(event);
            PushEvent(event);
        } break;

        case sf::Event::MouseButtonPressed: {
            MouseButton button_id = MouseButton((int)sfml_event.mouseButton.button);
            MousePressedEvent event(button_id, mouse_pos);
            SetControlButton(event);
            PushEvent(event);
        } break;

        case sf::Event::MouseButtonReleased: {
            MouseButton button_id = MouseButton((int)sfml_event.mouseButton.button);
            MouseReleasedEvent event(button_id, mouse_pos);
            SetControlButton(event);
            PushEvent(event);
        } break;

        case sf::Event::MouseWheelScrolled: {
            // Nothing
        } break;


        // Keyboard
        case sf::Event::KeyPressed: {
            KeyCode key_code = KeyCode(sfml_event.key.code);
            KeyboardPressedEvent event(key_code, mouse_pos);
            SetControlButton(event);
            PushEvent(event);

            // TODO: DELETE
            // Exit by q
            if (key_code == KeyCode::Q) {
                Stop();
            }
        } break;

        case sf::Event::KeyReleased: {
            KeyCode key_code = KeyCode(sfml_event.key.code);
            KeyboardReleasedEvent event(key_code, mouse_pos);
            SetControlButton(event);
            PushEvent(event);
        } break;

        case sf::Event::Resized: {
            assert(0);
        } break;

        case sf::Event::LostFocus: {
            /* Nothing */
        }

        default: {/* Nothing */}
    }
    }

#pragma GCC diagnostic pop
}

void Core::PushEvent(Event &event) {
    WTransformStack tr_stack;
    EHC ehc = {tr_stack};
    for (Widget* widget : widgets_) {
        widget->onEvent(event, ehc);
    }
}
