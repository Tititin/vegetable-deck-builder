#include "Deck.hpp"

Deck::Deck()
{
    _cardCounts[Card::VegetableType::ARTICHOKE] = 10;
}

Deck::~Deck()
{
}

Card::VegetableType Deck::drawCard()
{
    Card::VegetableType drawnType;
    std::uniform_int_distribution<int> distribution(0, 0); // Currently only one type of card available
    drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    while (!_cardCounts.contains(drawnType))
        drawnType = static_cast<Card::VegetableType>(distribution(Random::engine()));

    if (_cardCounts[drawnType] > 0) {
        _cardCounts[drawnType]--;
        return drawnType;
    }

    return (Card::VegetableType::ARTICHOKE);
}
