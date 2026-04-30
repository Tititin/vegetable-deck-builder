#include "Game.hpp"

Game::Game()
    :   _fontManager(),
        _textureManager(),
        _inputManager(),
        _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager, _fontManager),
        _cardManager(_textureManager, _fontManager),
        _playerHand(_inputManager, _textureManager),
        _garbage(_inputManager, _textureManager),
        _endTurnButton("End Turn", _fontManager),
        _pickCardButton("Pick Card", _fontManager),
        _winGameButton("Win Game", _fontManager)
{
}

Game::~Game()
{
}

void Game::init(sf::RenderWindow* window)
{
    _window = window;
    _cardManager.init();
    _inputManager.registerClickable(&_deck);
    _potager.loadSlots();
    _playerHand.init();
    _garbage.init();

    _endTurnButton.init();
    _inputManager.registerClickable(&_endTurnButton);

    _pickCardButton.init();
    _pickCardButton.setPosition({ 1700.f, 75.f });
    _inputManager.registerClickable(&_pickCardButton);

    _winGameButton.init();
    _winGameButton.setPosition({ 1700.f, 130.f });
    _winGameButton.setFillColor(sf::Color(0, 200, 0)); // Make the win game button green to distinguish it from the end turn button
    _winGameButton.setEnabled(false); // Disable the win game button at the start of the game
    _inputManager.registerClickable(&_winGameButton);

    for (int i = 0; i < 5; i++) {
        Card* newCard = _cardManager.createCard();
        _potager.addCard(newCard, i);
        _inputManager.registerClickable(newCard);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }
    for (int i = 0; i < 10; i++) {
        Card* newCard = _cardManager.createCard(Card::VegetableType::ARTICHOKE);
        _deck.addCard(newCard);
        _inputManager.registerClickable(newCard);
    }
}

void Game::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    _inputManager.handleEvent(event, window);
    retrieveStates();
}

void Game::retrieveStates()
{
    retrievePlayerHandState();
    retrieveDeckState();
    retrieveGarbageState();
    retrievePotagerState();
    retrieveEndTurnButtonState();
    retrievePickCardButtonState();
    retrieveWinGameButtonState();
}

void Game::display(sf::RenderTarget &target)
{
    target.clear();
    _potager.draw(target);
    _deck.draw(target);
    _deck.drawContent(target);
    _playerHand.draw(target);
    _garbage.draw(target);

    if (_endTurnButton.isEnabled())
        _endTurnButton.draw(target);
    if (_pickCardButton.isEnabled())
        _pickCardButton.draw(target);
    if (_winGameButton.isEnabled())
        _winGameButton.draw(target);
}

void Game::retrievePlayerHandState()
{
    switch(_playerHand.getState())
    {
        case PlayerHand::PlayerHandState::IDLE:
            break;
        case PlayerHand::PlayerHandState::WAITINGCARDS:
            break;
        case PlayerHand::PlayerHandState::CHOOSECARD:
            break;
        case PlayerHand::PlayerHandState::NOARTICHOKE:
            _winGameButton.setEnabled(true); // Enable the win game button if the player has no artichoke in hand
            _state = GameState::GAMEOVER; // Set the game state to game over
            break;
        case PlayerHand::PlayerHandState::DISCARDINGCARDS:
            while (_playerHand.getCards().size() > 0) {
                Card* card = _playerHand.discardCard();
                _garbage.addCard(card);
            }
            _playerHand.setState(PlayerHand::PlayerHandState::WAITINGCARDS);
                break;
            break;
    }
}

void Game::retrieveDeckState()
{
    switch(_deck.getState())
    {
        case Deck::DeckState::IDLE:
            break;
        case Deck::DeckState::PICKINGCARDS:
            if (_playerHand.getState() == PlayerHand::PlayerHandState::WAITINGCARDS) {
                for (int i = 0; _playerHand.getCards().size() < 5; i++) {
                    Card* drawnCard = _deck.drawRandomCard();
                    if (drawnCard) {
                        _playerHand.addCard(drawnCard);
                        drawnCard->setPosition(_playerHand.getSlotPosition(_playerHand.getCards().size() - 1));
                        drawnCard->updateScale(PLAYER_HAND_SPRITE_SCALE);
                    }
                    else
                    {
                        _deck.setState(Deck::DeckState::EMPTYDECK);
                        break;
                    }
                }
                if (_playerHand.getCards().size() >= 5)
                {
                    _playerHand.setState(PlayerHand::PlayerHandState::CHOOSECARD);
                    _playerHand.runHandAnalysis(); // Check if the player has an artichoke in hand after drawing cards
                    _deck.setState(Deck::DeckState::IDLE);
                }
            }
            else if (_playerHand.getState() == PlayerHand::PlayerHandState::IDLE)
                _deck.setState(Deck::DeckState::IDLE);
            break;
        case Deck::DeckState::EMPTYDECK:
            for (auto* card : _garbage.getCardsInGarbage())
                _deck.addCard(_garbage.drawCardFromGarbage());
            _deck.setState(Deck::DeckState::PICKINGCARDS);
            break;
    }
}

void Game::retrieveGarbageState()
{
    switch(_garbage.getState())
    {
        case Garbage::GarbageState::IDLE:
            break;
        case Garbage::GarbageState::RESTORINGDECK:
            break;
    }
}

void Game::retrievePotagerState()
{
    switch (_potager.getState())
    {
        case Potager::PotagerState::IDLE:
            break;
        case Potager::PotagerState::WAITINGCOMPLETION:
            for (int i = 0; i < _potager.getElements().size(); i++)
            {
                if (_potager.getElements()[i] == nullptr)
                {
                    Card* newCard = _cardManager.createCard();
                    if (!newCard) {
                        _window->close(); // Close the window if no more cards can be created (should not happen in normal gameplay)
                        break;
                    }
                    _potager.addCard(newCard, i);
                    _inputManager.registerClickable(newCard);
                    newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
                }
            }
            _potager.setState(Potager::PotagerState::IDLE);
            break;
    }
}

void Game::retrieveEndTurnButtonState()
{
    switch (_endTurnButton.getClickState())
    {
        case Clickable::ClickState::NONE:
            break;
        case Clickable::ClickState::PRESSED:
            // For testing purposes, pressing the end turn button will move all cards from player hand to garbage
            _playerHand.setState(PlayerHand::PlayerHandState::DISCARDINGCARDS);
            _endTurnButton.setClickState(Clickable::ClickState::NONE);
            _potager.setState(Potager::PotagerState::WAITINGCOMPLETION);
            break;
    }
}

void Game::retrievePickCardButtonState()
{
    switch (_pickCardButton.getClickState())
    {
        case Clickable::ClickState::NONE:
            break;
        case Clickable::ClickState::PRESSED:
            if (_playerHand.getState() == PlayerHand::PlayerHandState::CHOOSECARD)
                {
                    for (int i = 0; i < _potager.getElements().size(); i++)
                    {
                        if (_potager.getElements()[i] && _potager.getElements()[i]->getClickState() == Clickable::ClickState::PRESSED)
                        {
                            Card* card = dynamic_cast<Card*>(_potager.getElements()[i]);
                            if (card) {
                                _playerHand.addCard(card);
                                card->setPosition(_playerHand.getSlotPosition(_playerHand.getCards().size() - 1));
                                card->updateScale(PLAYER_HAND_SPRITE_SCALE);
                                _potager.getElements()[i] = nullptr;
                                _inputManager.releaseAllClickables(); // Release all clickables to reset their states
                                _playerHand.setState(PlayerHand::PlayerHandState::IDLE);
                            }
                        }
                    }
                }
                _pickCardButton.setClickState(Clickable::ClickState::NONE);
            break;
    }
}

void Game::retrieveWinGameButtonState()
{
    switch (_winGameButton.getClickState())
    {
        case Clickable::ClickState::NONE:
            break;
        case Clickable::ClickState::PRESSED:
            if (_winGameButton.isEnabled())
            {
                _window->close(); // Close the window to simulate winning the game
                _winGameButton.setClickState(Clickable::ClickState::NONE);
            }
            break;
    }
}
