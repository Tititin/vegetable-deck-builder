#pragma once

#include "Clickable.hpp"

class SpriteClickable : public Clickable {
    protected:

    sf::Sprite _sprite;
    sf::RectangleShape _border;

    public:
        SpriteClickable(const sf::Texture& texture) : _sprite(texture) {}
        ~SpriteClickable() = default;

        virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;
        virtual void init() = 0;

        virtual sf::Sprite& getSprite() { return _sprite; }
        virtual sf::FloatRect getGlobalBounds() const { return _sprite.getGlobalBounds(); }
        virtual sf::Vector2f getPosition() const { return _sprite.getPosition(); }
        virtual void setPosition(const sf::Vector2f& position) { _sprite.setPosition(position); }
        virtual sf::RectangleShape& getBorder() { return _border; }

        virtual bool contains(const sf::Vector2f& point) override { return _sprite.getGlobalBounds().contains(point); };
};