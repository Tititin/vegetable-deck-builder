#include "PlayerHand.hpp"

PlayerHand::PlayerHand(InputManager &inputManager, TextureManager &textureManager)
: _inputManager(&inputManager), _textureManager(&textureManager)
{
}

PlayerHand::~PlayerHand()
{
}
