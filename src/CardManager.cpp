#include "lib/Random.hpp"
#include "CardManager.hpp"

int CardManager::getRemainingCardsNumber()
{
    int total = 0;
    for (const auto &pair : _remainingCardsToCreate) {
        total += pair.second;
    }
    return total;
}

CardManager::CardManager(TextureManager &textureManager, FontManager &fontManager)
    :   _textureManager(&textureManager),
        _fontManager(&fontManager)
{
}

CardManager::~CardManager()
{
}

void CardManager::init()
{
    _remainingCardsToCreate[Card::VegetableType::ARTICHOKE] = NB_CARDS_ARTICHOKE;
    _remainingCardsToCreate[Card::VegetableType::ONION] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::CORN] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::POTATO] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::EGGPLANT] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::PEAS] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::CARROT] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::BROCCOLI] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::LEEK] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::RHUBARB] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::BELLPEPPER] = NB_CARDS_PER_TYPE;
    _remainingCardsToCreate[Card::VegetableType::BEETROOT] = NB_CARDS_PER_TYPE;
}

Card *CardManager::createCard()
{
    std::uniform_int_distribution<int> distribution(1, 11);
    Card::VegetableType type;
    
    do
    {
        type = static_cast<Card::VegetableType>(distribution(Random::engine()));
    } while (_remainingCardsToCreate[type] == 0 && getRemainingCardsNumber() > 0);
    _remainingCardsToCreate[type] -= 1;

    if (getRemainingCardsNumber() == 0)
        return nullptr;
    return new Card(type, *_textureManager, _fontManager->getFont("CreatoDisplay-Regular"));
}

Card *CardManager::createCard(const Card::VegetableType &type)
{
    if (_remainingCardsToCreate[type] > 0) {
        _remainingCardsToCreate[type] -= 1;
        return new Card(type, *_textureManager, _fontManager->getFont("CreatoDisplay-Regular"));
    }
    return nullptr;
}
