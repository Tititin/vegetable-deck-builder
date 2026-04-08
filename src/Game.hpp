#pragma once

#include "Card.hpp"
#include "CardManager.hpp"
#include "Deck.hpp"
#include "Garbage.hpp"
#include "InputManager.hpp"
#include "PlayerHand.hpp"
#include "Potager.hpp"
#include "TextureManager.hpp"

class Game {
private:
    CardManager     _cardManager;
    InputManager    _inputManager;
    TextureManager  _textureManager;
    Potager         _potager;
    Deck            _deck;
    // Garbage         _garbage;
    PlayerHand      _playerHand;

public:
    Game();
    ~Game();

    CardManager& getCardManager() { return _cardManager; }
    InputManager& getInputManager() { return _inputManager; }
    TextureManager& getTextureManager() { return _textureManager; }
    Potager& getPotager() { return _potager; }
    Deck& getDeck() { return _deck; }
    // Garbage& getGarbage() { return _garbage; }
    PlayerHand& getPlayerHand() { return _playerHand; }

    void init();

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void retrieveStates();

    void display(sf::RenderTarget& target);

private:
    void retrievePlayerHandState();
};