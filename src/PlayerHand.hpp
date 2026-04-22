#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "SpriteClickable.hpp"
#include "Card.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"
#include "lib/Params.hpp"

class PlayerHand {
    public:
        enum class PlayerHandState {
            IDLE,
            WAITINGCARDS,
            CHOOSECARD,
            NOARTICHOKE,
            DISCARDINGCARDS
        };

    private:
        std::vector<Card*> _cards; // Cards currently in the player's hand
        std::vector<sf::Sprite> _slots;

        InputManager* _inputManager;
        TextureManager* _textureManager;
        PlayerHandState _state;

    public:
        PlayerHand(InputManager& inputManager, TextureManager& textureManager);
        ~PlayerHand();

        void init();

        void addCard(Card* card);
        Card* discardCard();

        void setState(PlayerHandState state) { _state = state; }
        PlayerHandState getState() const { return _state; }
        const sf::Vector2f  getSlotPosition(int index) const { return _slots[index].getPosition(); }
        const std::vector<Card*>& getCards() const { return _cards; }

        void runHandAnalysis();

        void draw(sf::RenderTarget& target);
};