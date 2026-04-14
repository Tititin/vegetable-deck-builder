#include "Game.hpp"

Game::Game()
    :   _fontManager(),
        _textureManager(),
        _inputManager(),
        _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager, _fontManager),
        _cardManager(_textureManager),
        _playerHand(_inputManager, _textureManager),
        _garbage(_inputManager, _textureManager),
        _endTurnButton("End Turn", _fontManager)
{
}

Game::~Game()
{
}

void Game::init()
{
    _cardManager.init();
    _inputManager.registerClickable(&_deck);
    _potager.loadSlots();
    _playerHand.init();
    _garbage.init();
    _endTurnButton.init();

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
    // TEST: Pressing G key will move all cards from player hand to garbage
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::G)) {
        _playerHand.setState(PlayerHand::PlayerHandState::DISCARDINGCARDS);
    }
    // END TEST
    retrieveStates();
}

void Game::retrieveStates()
{
    retrievePlayerHandState();
    retrieveDeckState();
    retrieveGarbageState();
}

void Game::display(sf::RenderTarget &target)
{
    target.clear();
    _potager.draw(target);
    _deck.draw(target);
    _deck.drawContent(target);
    _playerHand.draw(target);
    _garbage.draw(target);
    _endTurnButton.draw(target);
}

void Game::retrievePlayerHandState()
{
    switch(_playerHand.getState())
    {
        case PlayerHand::PlayerHandState::IDLE:
            break;
        case PlayerHand::PlayerHandState::WAITINGCARDS:
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
    // _playerHand.setState(PlayerHand::PlayerHandState::IDLE);
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
                    _playerHand.setState(PlayerHand::PlayerHandState::IDLE);
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
