#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Clickable {
private:
    sf::RectangleShape _hitbox;
    std::function<void()> _onClick;
public:
    //Callbacks
    using ClickCallback = std::function<void(Clickable&)>;

    virtual ~Clickable() = default;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;
};