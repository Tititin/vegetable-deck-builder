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
                    bool isDoubleClick = (_lastClicked == clickable && _lastClickClock.getElapsedTime() < _doubleClickThreshold);
                    
                    if (isDoubleClick && clickable->getOnDoubleClick())
                    {
                        clickable->getOnDoubleClick()(*clickable);
                    }
                    else if (clickable->getOnClick())
                    {
                        clickable->getOnClick()(*clickable);
                    }
                    
                    // Release other pressed clickables
                    for (auto* otherClickable : _clickables)
                    {
                        if (otherClickable != clickable && otherClickable->getClickState() == Clickable::ClickState::PRESSED)
                        {
                            if (otherClickable->getOnClickRelease())
                                otherClickable->getOnClickRelease()(*otherClickable);
                        }
                    }
                    
                    // Update last click
                    _lastClicked = clickable;
                    _lastClickClock.restart();
                    
                    break; // Assuming only one clickable should respond to a click
                }
                else
                {
                    if (clickable->getOnClickRelease())
                        clickable->getOnClickRelease()(*clickable);
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
