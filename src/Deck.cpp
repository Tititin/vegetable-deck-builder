#include "Deck.hpp"

Deck::Deck(TextureManager& textureManager)
:   _deckSprite(textureManager.getTexture("card_back")),
    _deckTexture(&textureManager.getTexture("card_back"))
{
    _cardCounts[Card::VegetableType::ARTICHOKE] = 10;

    _deckSprite.setPosition({600.f, 800.f});
    _deckSprite.setScale({0.309f, 0.309f}); // Scale to fit the window
}

Deck::~Deck()
{
}

Card::VegetableType Deck::drawCard()
{
    Card::VegetableType drawnType;
    std::uniform_int_distribution<int> distribution(0, 0); // Currently only one type of card available
    drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    while (!_cardCounts.contains(drawnType) or _cardCounts[drawnType] <= 0)
        drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    if (_cardCounts[drawnType] > 0) {
        _cardCounts[drawnType]--;
        return drawnType;
    }

    return (Card::VegetableType::ARTICHOKE);
}
