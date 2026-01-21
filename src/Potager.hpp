#pragma once

// #include <SFML/Graphics.hpp>
#include <vector>
#include "Clickable.hpp"

class Potager {
private:
    std::vector<Clickable*> _elements;
    std::vector<sf::Sprite> _slots;

    sf::Texture*            _slotTexture;
public:
    Potager(const sf::Texture& slotTexture);
    ~Potager();

    void    loadSlots();

    void    addElement(Clickable* element);
    
    std::vector<Clickable*>& getElements() { return _elements; }

    // SFML Methods
    void    draw(sf::RenderTarget& target) const;
};