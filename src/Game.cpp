#include "Game.hpp"

Game::Game()
    : _potager(_textureManager.getTexture("potager_slot")),
        _deck(_inputManager, _textureManager)
{
}

Game::~Game()
{
}
