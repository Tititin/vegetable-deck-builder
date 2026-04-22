#include "Garbage.hpp"

Garbage::Garbage(InputManager &inputManager, TextureManager &textureManager)
: SpriteClickable(textureManager.getTexture("potager_slot")),
  _inputManager(&inputManager),
  _textureManager(&textureManager)
{
}

Garbage::~Garbage()
{
}

void Garbage::init()
{
    _sprite.setPosition({ 1620.f, 800.f });
    _sprite.setScale({CARD_SPRITE_SCALE, CARD_SPRITE_SCALE}); // Scale to fit the window
}

void Garbage::addCard(Card *card)
{
    _cardsInGarbage.push_back(std::move(card));
    card->setPosition(_sprite.getPosition());
    card->getSprite().setScale({CARD_SPRITE_SCALE, CARD_SPRITE_SCALE});
}

Card *Garbage::drawCardFromGarbage()
{
    if (!_cardsInGarbage.empty()) {
        Card* card = _cardsInGarbage.back();
        _cardsInGarbage.pop_back();
        return card;
    }
    return nullptr;
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

void Garbage::click(MouseClickState clickState)
{
}

void Garbage::draw(sf::RenderTarget &target) const
{
    target.draw(_sprite);
    if (!_cardsInGarbage.empty())
        target.draw(_cardsInGarbage.back()->getSprite());
}
