#include "PlayerHand.hpp"

PlayerHand::PlayerHand(InputManager &inputManager, TextureManager &textureManager)
: _inputManager(&inputManager), _textureManager(&textureManager)
{
}

PlayerHand::~PlayerHand()
{
}

void PlayerHand::init()
{
    for (int i = 0; i < 6; i++) {
        sf::Sprite slot(_textureManager->getTexture("potager_slot"));
        slot.setPosition({ static_cast<float>(350 + i * 200), 850.f });
        slot.setScale({PLAYER_HAND_SPRITE_SCALE, PLAYER_HAND_SPRITE_SCALE});
        slot.setColor(sf::Color(255, 255, 255, 64)); // Slightly transparent
        _slots.push_back(slot);
    }
    _state = PlayerHandState::WAITINGCARDS;
}

void PlayerHand::addCard(Card *card)
{
    _cards.push_back(card);
    _cards.back()->getSprite().setScale({PLAYER_HAND_SPRITE_SCALE, PLAYER_HAND_SPRITE_SCALE});
}

Card *PlayerHand::discardCard()
{
    if (!_cards.empty()) {
        Card* card = _cards.back();
        _cards.pop_back();
        return card;
    }
    return nullptr;
}

void PlayerHand::runHandAnalysis()
{
    for (int i = 0; i < _cards.size(); i++) {
        if (_cards[i]->getType() == Card::VegetableType::ARTICHOKE) {
            return; // If the player has at least one artichoke, return without doing anything
        }
    }
    _state = PlayerHandState::NOARTICHOKE; // If the player has no artichoke, set the state to NOARTICHOKE
}

void PlayerHand::draw(sf::RenderTarget &target)
{
    for (const auto& slot : _slots) {
        target.draw(slot);
    }
    for (const auto& card : _cards) {
        card->draw(target);
    }
}
