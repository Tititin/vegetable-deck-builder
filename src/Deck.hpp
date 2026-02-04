#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Card.hpp"
#include "TextureManager.hpp"
#include "lib/Random.hpp"

class Deck {
    private:
        std::map<Card::VegetableType, int> _cardCounts;

    public:
        Deck();
        ~Deck();

        Card::VegetableType drawCard();
};