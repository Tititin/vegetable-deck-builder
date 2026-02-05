#pragma once

#include <SFML/Graphics.hpp>
#include <functional>

class Clickable {
public:
    //Callbacks
    using ClickCallback = std::function<void(Clickable&)>;
    using ClickReleaseCallback = std::function<void(Clickable&)>;

    enum class ClickState {
        NONE,
        PRESSED
    };

    Clickable(const sf::Texture& texture) : _sprite(texture) {}

    virtual ~Clickable() = default;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;

    virtual sf::Sprite& getSprite() { return _sprite; }
    virtual sf::FloatRect getGlobalBounds() const { return _sprite.getGlobalBounds(); }
    virtual sf::Vector2f getPosition() const { return _sprite.getPosition(); }
    virtual void setPosition(const sf::Vector2f& position) { _sprite.setPosition(position); }

    virtual ClickState getClickState() const { return _clickState; }
    virtual void setClickState(ClickState state) { _clickState = state; }

    virtual ClickCallback getOnClick() const { return _onClick; }
    virtual ClickCallback getOnClickRelease() const { return _onClickRelease; }
    virtual ClickCallback getOnDoubleClick() const { return _onDoubleClick; }
    virtual bool contains(const sf::Vector2f& point) const { return _sprite.getGlobalBounds().contains(point); }

    virtual void click() = 0;

protected:
    ClickCallback _onClick;
    ClickCallback _onClickRelease;
    ClickCallback _onDoubleClick;

    sf::Sprite      _sprite;
    sf::RectangleShape   _bounds;

    ClickState      _clickState = ClickState::NONE;
};