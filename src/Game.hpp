#pragma once

#include <SFML/Graphics.hpp>
#include "Card.hpp"
#include "Deck.hpp"
#include "Garbage.hpp"
#include "PlayerHand.hpp"
#include "Potager.hpp"
#include "InputManager.hpp"
#include "TextureManager.hpp"

class Game {
private:
    InputManager    _inputManager;
    TextureManager  _textureManager;
    // Potager         _potager;
    // Deck            _deck;
    // Garbage         _garbage;
    // PlayerHand      _playerHand;

public:
    Game();
    ~Game();

    InputManager& getInputManager() { return _inputManager; }
    TextureManager& getTextureManager() { return _textureManager; }
};