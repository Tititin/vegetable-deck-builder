#pragma once

#include "Card.hpp"
#include "CardManager.hpp"
#include "Compost.hpp"
#include "Deck.hpp"
#include "FontManager.hpp"
#include "Garbage.hpp"
#include "InputManager.hpp"
#include "PlayerHand.hpp"
#include "Potager.hpp"
#include "TextureManager.hpp"
#include "ui/TextButton.hpp"

class Game {
private:
    enum class GameState {
        PLAY,
        GAMEOVER
    };

    InputManager    _inputManager;
    TextureManager  _textureManager;
    FontManager     _fontManager;
    CardManager     _cardManager;
    Potager         _potager;
    Deck            _deck;
    Garbage         _garbage;
    PlayerHand      _playerHand;
    TextButton      _endTurnButton;
    TextButton      _pickCardButton;
    TextButton      _winGameButton;

    sf::RenderWindow*   _window;

    GameState _state;

public:
    Game();
    ~Game();

    CardManager& getCardManager() { return _cardManager; }
    InputManager& getInputManager() { return _inputManager; }
    TextureManager& getTextureManager() { return _textureManager; }
    FontManager& getFontManager() { return _fontManager; }
    Potager& getPotager() { return _potager; }
    Deck& getDeck() { return _deck; }
    Garbage& getGarbage() { return _garbage; }
    PlayerHand& getPlayerHand() { return _playerHand; }

    void init(sf::RenderWindow* window);

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window);
    void retrieveStates();

    void display(sf::RenderTarget& target);

private:
    void retrievePlayerHandState();
    void retrieveDeckState();
    void retrieveGarbageState();
    void retrievePotagerState();
    void retrieveEndTurnButtonState();
    void retrievePickCardButtonState();
    void retrieveWinGameButtonState();
};