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

        // SFML Attributes
        sf::Sprite      _deckSprite;
        sf::Texture*    _deckTexture;

    public:
        Deck(TextureManager& textureManager);
        ~Deck();

        Card::VegetableType drawCard();

        // SFML Getters
        sf::Sprite& getSprite() { return _deckSprite; }

        // SFML Setters
        void setPosition(const sf::Vector2f& position) { _deckSprite.setPosition(position); }

        // Display
        void draw(sf::RenderTarget& target) const { target.draw(_deckSprite); }
};