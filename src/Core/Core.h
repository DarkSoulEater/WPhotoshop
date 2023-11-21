#ifndef ___CORE_H___
#define ___CORE_H___

#include "UI/Widget.h"
#include "Core/Event.h"

class Core {
public:
    Core();

    void Run();
    void Stop();

    void AddSeeker(Widget& widget);

private:
    void Clear();
    void Display();
    void Draw();

    void Tick();
    void PollEvent();
    void PushEvent(Event& event);

private:
    sf::RenderWindow main_window_;

    std::vector<Widget*> widgets_;
};

#endif // ___CORE_H___