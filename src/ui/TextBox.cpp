#include "TextBox.hpp"

TextBox::TextBox(const sf::Font &font, const std::string &str, unsigned int characterSize)
    : _text(font)
{
    _text.setString(str);
    _text.setCharacterSize(characterSize);
}

void TextBox::setPosition(const sf::Vector2f &position)
{
    _box.setPosition(position);
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

void TextBox::draw(sf::RenderTarget &target) const
{
    target.draw(_box);
    target.draw(_text);
}
