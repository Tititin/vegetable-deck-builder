#pragma once

#include <SFML/Graphics.hpp>
#include "../lib/Params.hpp"

class TextBox {
    private:
        sf::RectangleShape _box;
        sf::Text _text;

        bool _isVisible = true;

    public:
        TextBox(const sf::Font& font, const std::string& str, unsigned int characterSize = 10);
        ~TextBox() = default;

        void setPosition(const sf::Vector2f& position);
        void setSize(const sf::Vector2f& size);
        void setString(const std::string& str);
        void setFillColor(const sf::Color& color);
        void setTextColor(const sf::Color& color);
        void setCharacterSize(unsigned int size);
        void setOutlineColor(const sf::Color& color);
        void setOutlineThickness(float thickness);
        void setVisible(bool visible);

        bool isVisible() const { return _isVisible; }

        void draw(sf::RenderTarget& target) const;
};