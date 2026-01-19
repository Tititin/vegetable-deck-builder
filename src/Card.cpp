#include "Card.hpp"

Card::Card(const std::string& name, const sf::Texture& backTexture, const sf::Texture& frontTexture)
    : _name(name), _cardSprite(backTexture), _backTexture(const_cast<sf::Texture*>(&backTexture)), _frontTexture(const_cast<sf::Texture*>(&frontTexture))
{
    _cardSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
    setOnClick([this](Clickable&){
        this->flipCard();
    });
}

Card::~Card()
{
}

void Card::setOnClick(ClickCallback callback)
{
    _onClick = std::move(callback);
}

void Card::handleEvent(const sf::Event& event, const sf::RenderWindow& window)
{
    if (const auto mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            const auto mousePos = window.mapPixelToCoords({mouseButtonPressed->position});

            if (_cardSprite.getGlobalBounds().contains(mousePos))
            {
                if (_onClick)
                    _onClick(*this);
            }
        }
    }
}

void Card::flipCard()
{
    (this->_currentFace == Face::BACK) ? showFront() : showBack();
}

void Card::showFront()
{
    _cardSprite.setTexture(*_frontTexture);
    _currentFace = Face::FRONT;
}

void Card::showBack()
{
    _cardSprite.setTexture(*_backTexture);
    _currentFace = Face::BACK;
}
