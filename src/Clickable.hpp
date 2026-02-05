#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Clickable {
protected:
    enum class ClickState {
        NONE,
        PRESSED
    };

    std::function<void()> _onClick;

    sf::Sprite      _sprite;

    ClickState      _clickState = ClickState::NONE;
public:
    //Callbacks
    using ClickCallback = std::function<void(Clickable&)>;
    using ClickReleaseCallback = std::function<void(Clickable&)>;

    Clickable(const sf::Texture& texture) : _sprite(texture) {}

    virtual ~Clickable() = default;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;

    virtual sf::Sprite& getSprite() { return _sprite; }
    virtual sf::FloatRect getGlobalBounds() const { return _sprite.getGlobalBounds(); }
    virtual sf::Vector2f getPosition() const { return _sprite.getPosition(); }
    virtual void setPosition(const sf::Vector2f& position) { _sprite.setPosition(position); }

    virtual ClickState getClickState() const { return _clickState; }
    virtual void setClickState(ClickState state) { _clickState = state; }

    virtual bool contains(const sf::Vector2f& point) const { return _sprite.getGlobalBounds().contains(point); }
};