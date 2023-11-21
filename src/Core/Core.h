#ifndef ___CORE_H___
#define ___CORE_H___

#include <vector>
#include "SFML/Graphics.hpp"
#include "UI/Widget.h"
#include "Core/Event.h"
#include "Graphics/Graphics.h"

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
    SFMLRenderTarget rt_window_; // TODO: add init in ctor

    std::vector<Widget*> widgets_;
};

#endif // ___CORE_H___