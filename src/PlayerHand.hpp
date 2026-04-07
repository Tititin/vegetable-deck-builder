#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Clickable.hpp"
#include "Card.hpp"
#include "TextureManager.hpp"
#include "InputManager.hpp"

class PlayerHand {
    private:
        std::vector<Card*> _cards; // Cards currently in the player's hand

        InputManager* _inputManager;
        TextureManager* _textureManager;
    public:
        PlayerHand(InputManager& inputManager, TextureManager& textureManager);
        ~PlayerHand();
};