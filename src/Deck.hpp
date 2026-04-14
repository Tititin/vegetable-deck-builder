#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "SpriteClickable.hpp"
#include "Card.hpp"
#include "FontManager.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "lib/Random.hpp"

class Deck : public SpriteClickable {
    public:
        enum class DeckState {
            IDLE,
            PICKINGCARDS,
            EMPTYDECK
        };
    private:
        std::vector<Card*> _cards; // Cards currently in the deck

        InputManager*   _inputManager;
        TextureManager* _textureManager;
        FontManager*    _fontManager;
        DeckState _state;

        // SFML Attributes
        sf::Texture*    _deckTexture;
        sf::Text        _deckCountText; // For develop versions only: display number of cards left by type

    public:
        Deck(InputManager& inputManager, TextureManager& textureManager, FontManager& fontManager);
        ~Deck();

        virtual void init() override;

        void    addCard(Card* card);
        Card*   drawRandomCard();

        const std::vector<Card*>& getCards() const { return _cards; }

        // Callbacks
        void setOnClick(ClickCallback callback);
        void setOnClickRelease(ClickReleaseCallback callback);

        // Event Handling
        virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
        virtual void click() override;
        DeckState getState() const { return _state; }
        void setState(DeckState state) { _state = state; }

        // Display
        void draw(sf::RenderTarget& target);
        void drawContent(sf::RenderTarget& target);
};