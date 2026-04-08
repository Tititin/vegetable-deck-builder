#include "Game.hpp"

Game::Game()
    :   _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager),
        _cardManager(_textureManager),
        _playerHand(_inputManager, _textureManager),
        _garbage(_inputManager, _textureManager)
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
            for (auto* card : _playerHand.getCards())
                _garbage.addCard(std::move(card));
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
                for (int i = 0; i < 5; i++) {
                    Card* drawnCard = _deck.drawRandomCard();
                    if (drawnCard) {
                        _playerHand.addCard(drawnCard);
                        drawnCard->setPosition(_playerHand.getSlotPosition(i));
                        drawnCard->updateScale(PLAYER_HAND_SPRITE_SCALE);
                    }
                }
                _playerHand.setState(PlayerHand::PlayerHandState::IDLE);
            }
            _deck.setState(Deck::DeckState::IDLE);
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
