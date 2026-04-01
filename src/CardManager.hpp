#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Clickable.hpp"
#include "Card.hpp"

class CardManager {
protected:
    std::map<Card::VegetableType, int> _remainingCardsToCreate; // Map to keep track of the number of each type of card in the deck

    TextureManager* _textureManager;

public:
    CardManager(TextureManager& textureManager);
    ~CardManager();

    void init();

    Card* createCard();
};