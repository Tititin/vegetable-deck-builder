#pragma once

#include "../lib/Params.hpp"
#include "../lib/Enums.hpp"
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
        virtual void click(MouseClickState clickState) override;
        virtual bool contains(const sf::Vector2f& point) override { return _buttonShape.getGlobalBounds().contains(point); };

        virtual void setPosition(const sf::Vector2f& position) { _buttonShape.setPosition(position); }
        virtual void setSize(const sf::Vector2f& size) { _buttonShape.setSize(size); }
        virtual void setFillColor(const sf::Color& color) { _buttonShape.setFillColor(color); }

        void draw(sf::RenderTarget& target) const { target.draw(_buttonShape); }
};