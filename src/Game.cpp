#include "Game.hpp"

Game::Game()
    :   _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager),
        _cardManager(_textureManager)
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

    for (int i = 0; i < 5; i++) {
        Card* newCard = _cardManager.createCard();
        _potager.addCard(newCard, i);
        _inputManager.registerClickable(newCard);
        newCard->setPosition({ static_cast<float>(350 + i * 250), 400.f });
    }
    for (int i = 0; i < 6; i++) {
        Card* newCard = _cardManager.createCard(Card::VegetableType::ONION);
        _deck.addCard(newCard);
    }
}

void Game::handleEvent(const sf::Event &event, const sf::RenderWindow &window)
{
    _inputManager.handleEvent(event, window);
}

void Game::display(sf::RenderTarget &target)
{
    target.clear();
    _potager.draw(target);
    _deck.draw(target);
    // for (auto* card : _deck.getCards()) { // Maybe do this in Deck::draw() in v0.5.0 ?
    //     target.draw(card->getSprite());
    // }
    _deck.drawContent(target);
}
