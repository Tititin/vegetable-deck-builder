#include "TextButton.hpp"

TextButton::TextButton(const std::string &text)
    : BasicButton(),
        _buttonFont("assets/fonts/CreatoDisplay-Regular.otf"),
        _buttonText(_buttonFont)
{
    _buttonText.setString(text);
    _buttonText.setCharacterSize(BASIC_BUTTON_TEXT_SIZE);
    _buttonText.setFillColor(BASIC_BUTTON_TEXT_COLOR);
}

void TextButton::init()
{
    BasicButton::init();
    _buttonText.setOrigin({_buttonText.getLocalBounds().size.x / 2.f, _buttonText.getLocalBounds().size.y / 2.f});
    _buttonText.setPosition({_buttonShape.getPosition().x + BASIC_BUTTON_WIDTH / 2.f, _buttonShape.getPosition().y + BASIC_BUTTON_HEIGHT / 2.f});
}
