#include "BasicButton.hpp"

BasicButton::BasicButton()
    : Clickable()
{
    setOnClick([this](Clickable&){
        click();
    });
    setOnClickRelease([this](Clickable&){
        click();
    });
}

void BasicButton::setOnClick(ClickCallback callback)
{
    _onClick = std::move(callback);
}

void BasicButton::setOnClickRelease(ClickReleaseCallback callback)
{
    _onClickRelease = std::move(callback);
}

void BasicButton::init()
{
    _buttonShape.setSize({BASIC_BUTTON_WIDTH, BASIC_BUTTON_HEIGHT});
    _buttonShape.setFillColor(BASIC_BUTTON_COLOR);
    _buttonShape.setPosition({1700.f, 20.f});
}

void BasicButton::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
}

void BasicButton::click()
{
}
