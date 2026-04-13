#pragma once

#include "../lib/Params.hpp"
#include "../Clickable.hpp"
#include "../InputManager.hpp"
#include "../TextureManager.hpp"

class BasicButton : public Clickable {
    protected:

    sf::RectangleShape _buttonShape;

    public:
        BasicButton();
        ~BasicButton() = default;

        void setOnClick(ClickCallback callback);
        void setOnClickRelease(ClickReleaseCallback callback);

        virtual void init() override;
        virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
        virtual void click() override;
        virtual bool contains(const sf::Vector2f& point) override { return _buttonShape.getGlobalBounds().contains(point); };

        void draw(sf::RenderTarget& target) const { target.draw(_buttonShape); }
};