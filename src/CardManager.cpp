#include "lib/Random.hpp"
#include "CardManager.hpp"

CardManager::CardManager(TextureManager &textureManager)
    : _textureManager(&textureManager)
{
}

CardManager::~CardManager()
{
}

void CardManager::init()
{
    _remainingCardsToCreate[Card::VegetableType::ARTICHOKE] = 10;
    _remainingCardsToCreate[Card::VegetableType::ONION] = 6;
    _remainingCardsToCreate[Card::VegetableType::CORN] = 6;
    _remainingCardsToCreate[Card::VegetableType::POTATO] = 6;
    _remainingCardsToCreate[Card::VegetableType::EGGPLANT] = 6;
    _remainingCardsToCreate[Card::VegetableType::PEAS] = 6;
    _remainingCardsToCreate[Card::VegetableType::CARROT] = 6;
    _remainingCardsToCreate[Card::VegetableType::BROCCOLI] = 6;
    _remainingCardsToCreate[Card::VegetableType::LEEK] = 6;
    _remainingCardsToCreate[Card::VegetableType::RHUBARB] = 6;
    _remainingCardsToCreate[Card::VegetableType::BELLPEPPER] = 6;
    _remainingCardsToCreate[Card::VegetableType::BEETROOT] = 6;
}

Card *CardManager::createCard()
{
    std::uniform_int_distribution<int> distribution(1, 11);
    Card::VegetableType type;
    
    do
    {
        type = static_cast<Card::VegetableType>(distribution(Random::engine()));
    } while (_remainingCardsToCreate[type] == 0);
    _remainingCardsToCreate[type] -= 1;

    return new Card(type, *_textureManager);
}

Card *CardManager::createCard(const Card::VegetableType &type)
{
    if (_remainingCardsToCreate[type] > 0) {
        _remainingCardsToCreate[type] -= 1;
        return new Card(type, *_textureManager);
    }
    return nullptr;
}
