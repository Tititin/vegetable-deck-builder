#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Clickable.hpp"
#include "Card.hpp"
#include "TextureManager.hpp"
#include "lib/Random.hpp"

class Deck : public Clickable {
    private:
        std::map<Card::VegetableType, int> _cardCounts;

        // SFML Attributes
        sf::Texture*    _deckTexture;
        sf::Font        _deckFont;
        sf::Text        _deckCountText; // For v0.4.0 only: display number of cards left by type

        // Callbacks
        ClickCallback   _onClick;
        ClickCallback   _onClickRelease;

    public:
        Deck(TextureManager& textureManager);
        ~Deck();

        Card::VegetableType drawCard();

        // Callbacks
        void setOnClick(ClickCallback callback);
        void setOnClickRelease(ClickReleaseCallback callback);

        // Event Handling
        void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;

        // Display
        void draw(sf::RenderTarget& target) const { target.draw(_sprite); }
        void drawContent(sf::RenderTarget& target);
};