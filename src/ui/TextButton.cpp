#include "TextButton.hpp"

TextButton::TextButton(const std::string &text, FontManager& fontManager)
    : BasicButton(),
        _fontManager(&fontManager),
        _buttonText(fontManager.getFont("CreatoDisplay-Regular"))
{
    _buttonText.setString(text);
    _buttonText.setCharacterSize(BASIC_BUTTON_TEXT_SIZE);
    _buttonText.setFillColor(BASIC_BUTTON_TEXT_COLOR);
}

TextButton::TextButton(const std::string &text, const sf::Font &font)
    : BasicButton(),
        _fontManager(nullptr),
        _buttonText(font)
{
    _buttonText.setString(text);
    _buttonText.setCharacterSize(BASIC_BUTTON_TEXT_SIZE);
    _buttonText.setFillColor(BASIC_BUTTON_TEXT_COLOR);
}

void TextButton::init()
{
    BasicButton::init();
    _buttonText.setOrigin({_buttonText.getLocalBounds().size.x / 2.f, _buttonText.getLocalBounds().size.y / 2.f});
    _buttonText.setPosition({_buttonShape.getPosition().x + _buttonShape.getSize().x / 2.f, _buttonShape.getPosition().y + _buttonShape.getSize().y / 2.f - _buttonText.getLocalBounds().size.y / 2.f});
}

void TextButton::setPosition(const sf::Vector2f &position)
{
    BasicButton::setPosition(position);
    // _buttonText.setPosition({_buttonShape.getPosition().x + BASIC_BUTTON_WIDTH / 2.f, _buttonShape.getPosition().y + BASIC_BUTTON_HEIGHT / 2.f});
    _buttonText.setPosition({_buttonShape.getPosition().x + _buttonShape.getSize().x / 2.f, _buttonShape.getPosition().y + _buttonShape.getSize().y / 2.f - _buttonText.getLocalBounds().size.y / 2.f});
}
