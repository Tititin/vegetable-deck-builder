#include "Garbage.hpp"

Garbage::Garbage(InputManager &inputManager, TextureManager &textureManager)
: Clickable(textureManager.getTexture("potager_slot")),
  _inputManager(&inputManager),
  _textureManager(&textureManager)
{
}

Garbage::~Garbage()
{
}

void Garbage::addCard(Card *card)
{
    _cardsInGarbage.push_back(std::move(card));
}

void Garbage::setOnClick(ClickCallback callback)
{
}

void Garbage::setOnClickRelease(ClickReleaseCallback callback)
{
}

void Garbage::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
}

void Garbage::click()
{
}
