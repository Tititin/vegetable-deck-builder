#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Clickable.hpp"
#include "Card.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "lib/Random.hpp"

class Deck : public Clickable {
    private:
        std::vector<Card*> _cards; // Cards currently in the deck

        InputManager* _inputManager;
        TextureManager* _textureManager;

        // SFML Attributes
        sf::Texture*    _deckTexture;
        sf::Font        _deckFont; // For develop versions only
        sf::Text        _deckCountText; // For develop versions only: display number of cards left by type

    public:
        Deck(InputManager& inputManager, TextureManager& textureManager);
        ~Deck();

        void init();

        void    addCard(Card* card);
        Card*   drawRandomCard();

        const std::vector<Card*>& getCards() const { return _cards; }

        // Callbacks
        void setOnClick(ClickCallback callback);
        void setOnClickRelease(ClickReleaseCallback callback);

        // Event Handling
        void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
        void click();

        // Display
        void draw(sf::RenderTarget& target) const { target.draw(_sprite); }
        void drawContent(sf::RenderTarget& target);
};