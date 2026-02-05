#include "InputManager.hpp"

void InputManager::registerClickable(Clickable *clickable)
{
    _clickables.push_back(clickable);
}

void InputManager::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    if (const auto mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            const auto mousePos = window.mapPixelToCoords({mouseButtonPressed->position});

            for (auto* clickable : _clickables)
            {
                if (clickable->contains(mousePos))
                {
                    if (clickable->getOnClick())
                        clickable->getOnClick()(*clickable);
                    break; // Assuming only one clickable should respond to a click
                }
            }
        }
    }
    if (const auto mouseButtonReleased = event.getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouseButtonReleased->button == sf::Mouse::Button::Left)
        {
            for (auto* clickable : _clickables)
            {
                if (clickable->getClickState() == Clickable::ClickState::PRESSED)
                {
                    if (clickable->getOnClickRelease())
                        clickable->getOnClickRelease()(*clickable);
                    break; // Assuming only one clickable should respond to a click release
                }
            }
        }
    }
}
