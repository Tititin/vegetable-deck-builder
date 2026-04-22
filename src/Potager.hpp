#pragma once

// #include <SFML/Graphics.hpp>
#include <vector>
#include "SpriteClickable.hpp"

class Potager {
public:
    enum class PotagerState {
        IDLE,
        WAITINGCOMPLETION
    };
private:
    std::vector<SpriteClickable*> _elements;
    std::vector<sf::Sprite> _slots;

    PotagerState _state;

    sf::Texture*            _slotTexture;
public:
    Potager(const sf::Texture& slotTexture);
    ~Potager();

    void    loadSlots();

    void    addCard(SpriteClickable* card, const int& index);
    
    std::vector<SpriteClickable*>& getElements() { return _elements; }
    PotagerState getState() const { return _state; }
    void setState(PotagerState state) { _state = state; }

    // SFML Methods
    void    draw(sf::RenderTarget& target) const;
};