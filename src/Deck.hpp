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
        sf::Font        _deckFont;
        sf::Text        _deckCountText; // For v0.4.0 only: display number of cards left by type

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
        void drawContent(sf::RenderTarget& target);
};