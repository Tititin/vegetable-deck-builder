#include "Game.hpp"

Game::Game()
    : _potager(_textureManager.getTexture("potager_slot")),
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

void Game::display(sf::RenderTarget &target)
{
    target.clear();
    _potager.draw(target);
    _deck.draw(target);
    for (auto* card : _deck.getDrawnCards()) {
        target.draw(card->getSprite());
    }
    _deck.drawContent(target);
}
