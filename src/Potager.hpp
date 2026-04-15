#pragma once

// #include <SFML/Graphics.hpp>
#include <vector>
#include "SpriteClickable.hpp"

class Potager {
private:
    std::vector<SpriteClickable*> _elements;
    std::vector<sf::Sprite> _slots;

    sf::Texture*            _slotTexture;
public:
    Potager(const sf::Texture& slotTexture);
    ~Potager();

    void    loadSlots();

    void    addCard(SpriteClickable* card, const int& index);
    
    std::vector<SpriteClickable*>& getElements() { return _elements; }

    // SFML Methods
    void    draw(sf::RenderTarget& target) const;
};