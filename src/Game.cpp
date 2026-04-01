#include "Game.hpp"

Game::Game()
    :   _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager)
{
}

Game::~Game()
{
}

void Game::init()
{
    _potager.loadSlots();
    _inputManager.registerClickable(&_deck);
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
    for (auto* card : _deck.getDrawnCards()) { // Maybe do this in Deck::draw() in v0.5.0 ?
        target.draw(card->getSprite());
    }
    _deck.drawContent(target);
}
