#include "TextBox.hpp"

TextBox::TextBox(const sf::Font &font, const std::string &str, unsigned int characterSize)
    : _text(font)
{
    _text.setString(str);
    _text.setCharacterSize(characterSize);
    _text.setFillColor(sf::Color::Black);

    _box.setFillColor(sf::Color(255, 255, 255, 96)); // Semi-transparent white
    _box.setOutlineColor(sf::Color::Black);
    _box.setOutlineThickness(2.f);
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    _box.setPosition(position);
    _text.setPosition({position.x + 5.f, position.y + 5.f}); // Add some padding for the text
}

void TextBox::setSize(const sf::Vector2f &size)
{
    _box.setSize(size);
}

void TextBox::setString(const std::string &str)
{
    _text.setString(str);
}

void TextBox::setFillColor(const sf::Color &color)
{
    _box.setFillColor(color);
}

void TextBox::setTextColor(const sf::Color &color)
{
    _text.setFillColor(color);
}

void TextBox::setCharacterSize(unsigned int size)
{
    _text.setCharacterSize(size);
}

void TextBox::setOutlineColor(const sf::Color &color)
{
    _box.setOutlineColor(color);
}

void TextBox::setOutlineThickness(float thickness)
{
    _box.setOutlineThickness(thickness);
}

void TextBox::setVisible(bool visible)
{
    _isVisible = visible;
}

void TextBox::draw(sf::RenderTarget &target) const
{
    if (_isVisible) {
        target.draw(_box);
        target.draw(_text);
    }
}
