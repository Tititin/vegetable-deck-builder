#pragma once

#include <SFML/Graphics.hpp>

class TextBox {
    private:
        sf::RectangleShape _box;
        sf::Text _text;

    public:
        TextBox(const sf::Font& font, const std::string& str, unsigned int characterSize = 30);
        ~TextBox() = default;

        void setPosition(const sf::Vector2f& position);
        void setString(const std::string& str);
        void setFillColor(const sf::Color& color);
        void setTextColor(const sf::Color& color);
        void setCharacterSize(unsigned int size);
        void setOutlineColor(const sf::Color& color);
        void setOutlineThickness(float thickness);

        void draw(sf::RenderTarget& target) const;
};