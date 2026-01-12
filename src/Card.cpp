#include "Card.hpp"

Card::Card(const std::string& name, const sf::Texture& backTexture)
    : _name(name), _cardSprite(backTexture)
{
    _cardSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
}

Card::~Card()
{
}